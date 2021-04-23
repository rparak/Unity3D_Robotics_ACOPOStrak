/****************************************************************************
MIT License
Copyright(c) 2021 Roman Parak
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*****************************************************************************
Author   : Roman Parak
Email    : Roman.Parak @outlook.com
Github   : https://github.com/rparak
File Name: br_data_processing.cs
****************************************************************************/

// ------------------------------------------------------------------------------------------------------------------------//
// ----------------------------------------------------- LIBRARIES --------------------------------------------------------//
// ------------------------------------------------------------------------------------------------------------------------//

// -------------------- System -------------------- //
using System;
using System.Threading;
// -------------------- Unity -------------------- //
using UnityEngine;
// -------------------- OPCUA -------------------- //
using Opc.Ua;
using Opc.Ua.Client;
using Opc.Ua.Configuration;

// -------------------- Class {Global Variable} -> Main Control -------------------- //
public static class GlobalVariables_Main_Control
{
    // String //
    public static string[] opcua_config = new string[2];
    // Bool // 
    public static bool enable_r, enable_w;
    public static bool connect, disconnect;
}

// -------------------- Class {Global Variable} -> Main Control -------------------- //
public static class GlobalVariables_Main_Object_Detection
{
    // Bool // 
    public static bool[] camera_object_detection = new bool[2];
}

public static class GlobalVariables_OPC_UA_client
{
    // -------------------- ACOPOSTrak Shuttles -------------------- //
    //  NodeId  //
    public static NodeId[] shuttle_x_node = new NodeId[6] { "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[0].Position.X", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[1].Position.X", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[2].Position.X", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[3].Position.X", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[4].Position.X" , "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[5].Position.X" };
    public static NodeId[] shuttle_y_node = new NodeId[6] { "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[0].Position.Y", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[1].Position.Y", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[2].Position.Y", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[3].Position.Y", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[4].Position.Y", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[5].Position.Y" };
    public static NodeId[] shuttle_rot_y_node = new NodeId[6] { "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[0].Orientation.Angle1", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[1].Orientation.Angle1", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[2].Orientation.Angle1", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[3].Orientation.Angle1", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[4].Orientation.Angle1", "ns=6;s=::AsGlobalPV:gShuttleMon.Shuttle[5].Orientation.Angle1" };
    //  Float  //
    public static float[] shuttle_x = new float[6];
    public static float[] shuttle_y = new float[6];
    public static float[] shuttle_rot_y = new float[6];
    // -------------------- Service - Camera Control -------------------- //
    //  NodeId  //
    public static NodeId camera_id_node = "ns=6;s=::tCTRL_m:dt_service.index";
    //  INT  //
    public static int camera_id;
}


public class br_data_processing : MonoBehaviour
{
    // -------------------- ApplicationConfiguration -------------------- //
    private ApplicationConfiguration client_configuration_r_s = new ApplicationConfiguration();
    private ApplicationConfiguration[] client_configuration_r = new ApplicationConfiguration[6];
    // -------------------- EndpointDescription -------------------- //
    private EndpointDescription client_end_point_r_s;
    private EndpointDescription[] client_end_point_r = new EndpointDescription[6];
    // -------------------- Session -------------------- //
    private Session client_session_r_s;
    private Session[] client_session_r = new Session[6];
    // -------------------- Thread -------------------- //
    private Thread opcua_client_r_s_Thread;
    private Thread[] opcua_client_r_Thread = new Thread[6];
    // -------------------- Int -------------------- //
    private int main_br_state = 0;
    // -------------------- Bool -------------------- //
    public bool connect_opcua = false;

    // ------------------------------------------------------------------------------------------------------------------------//
    // ------------------------------------------------ INITIALIZATION {START} ------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//
    void Start()
    {
        // PLC IP Address
        GlobalVariables_Main_Control.opcua_config[0] = "127.0.0.1";
        // OPC UA Port Number
        GlobalVariables_Main_Control.opcua_config[1] = "4840";

        // ------------------------ Initialization { B&R/SMC Digital Twin {Control Robot} - OPC UA Read Data } ------------------------//
        // Control -> Start {Read OPCUA data}
        GlobalVariables_Main_Control.enable_r = true;
    }

    // ------------------------------------------------------------------------------------------------------------------------ //
    // ------------------------------------------------ MAIN FUNCTION {Cyclic} ------------------------------------------------ //
    // ------------------------------------------------------------------------------------------------------------------------ //
    private void Update()
    {
        switch (main_br_state)
        {
            case 0:
                {
                    // ------------------------ Wait State {Disconnect State} ------------------------//
                    if (GlobalVariables_Main_Control.connect == true)
                    {
                        // Control -> Start {Read OPCUA data}
                        GlobalVariables_Main_Control.enable_r = true;

                        // Initialization threading block
                        opcua_client_r_s_Thread = new Thread(() => OPCUa_r_s_thread_function(GlobalVariables_Main_Control.opcua_config[0], GlobalVariables_Main_Control.opcua_config[1]));
                        opcua_client_r_s_Thread.IsBackground = true;
                        // Start threading block
                        opcua_client_r_s_Thread.Start();

                        // Initialization threading block
                        opcua_client_r_Thread[0] = new Thread(() => OPCUa_r0_thread_function(GlobalVariables_Main_Control.opcua_config[0], GlobalVariables_Main_Control.opcua_config[1]));
                        opcua_client_r_Thread[0].IsBackground = true;
                        // Start threading block
                        opcua_client_r_Thread[0].Start();

                        // Initialization threading block
                        opcua_client_r_Thread[1] = new Thread(() => OPCUa_r1_thread_function(GlobalVariables_Main_Control.opcua_config[0], GlobalVariables_Main_Control.opcua_config[1]));
                        opcua_client_r_Thread[1].IsBackground = true;
                        // Start threading block
                        opcua_client_r_Thread[1].Start();

                        // Initialization threading block
                        opcua_client_r_Thread[2] = new Thread(() => OPCUa_r2_thread_function(GlobalVariables_Main_Control.opcua_config[0], GlobalVariables_Main_Control.opcua_config[1]));
                        opcua_client_r_Thread[2].IsBackground = true;
                        // Start threading block
                        opcua_client_r_Thread[2].Start();

                        // Initialization threading block
                        opcua_client_r_Thread[3] = new Thread(() => OPCUa_r3_thread_function(GlobalVariables_Main_Control.opcua_config[0], GlobalVariables_Main_Control.opcua_config[1]));
                        opcua_client_r_Thread[3].IsBackground = true;
                        // Start threading block
                        opcua_client_r_Thread[3].Start();

                        // Initialization threading block
                        opcua_client_r_Thread[4] = new Thread(() => OPCUa_r4_thread_function(GlobalVariables_Main_Control.opcua_config[0], GlobalVariables_Main_Control.opcua_config[1]));
                        opcua_client_r_Thread[4].IsBackground = true;
                        // Start threading block
                        opcua_client_r_Thread[4].Start();

                        // Initialization threading block
                        opcua_client_r_Thread[5] = new Thread(() => OPCUa_r5_thread_function(GlobalVariables_Main_Control.opcua_config[0], GlobalVariables_Main_Control.opcua_config[1]));
                        opcua_client_r_Thread[5].IsBackground = true;
                        // Start threading block
                        opcua_client_r_Thread[5].Start();

                        // go to connect state
                        main_br_state = 1;
                    }
                }
                break;
            case 1:
                {
                    // ------------------------ Data Processing State {Connect State} ------------------------//
                    if (GlobalVariables_Main_Control.disconnect == true)
                    {
                        // Control -> Start {Read OPCUA data}
                        GlobalVariables_Main_Control.enable_r = false;
                        // Control -> Start {Write OPCUA data}
                        GlobalVariables_Main_Control.enable_w = false;

                        // Abort threading block {OPCUA -> read data}
                        if (opcua_client_r_s_Thread.IsAlive == true && opcua_client_r_Thread[0].IsAlive == true && opcua_client_r_Thread[1].IsAlive == true && opcua_client_r_Thread[2].IsAlive == true
                            && opcua_client_r_Thread[3].IsAlive == true && opcua_client_r_Thread[4].IsAlive == true && opcua_client_r_Thread[5].IsAlive == true)
                        {
                            opcua_client_r_s_Thread.Abort();
                            opcua_client_r_Thread[0].Abort();
                            opcua_client_r_Thread[1].Abort();
                            opcua_client_r_Thread[2].Abort();
                            opcua_client_r_Thread[3].Abort();
                            opcua_client_r_Thread[4].Abort();
                            opcua_client_r_Thread[5].Abort();
                        }

                        if (opcua_client_r_s_Thread.IsAlive == false && opcua_client_r_Thread[0].IsAlive == false && opcua_client_r_Thread[1].IsAlive == false && opcua_client_r_Thread[2].IsAlive == false
                            && opcua_client_r_Thread[3].IsAlive == false && opcua_client_r_Thread[4].IsAlive == false && opcua_client_r_Thread[5].IsAlive == false)
                        {
                            // go to initialization state {wait state -> disconnect state}
                            main_br_state = 0;
                        }
                    }
                }
                break;
        }

        GlobalVariables_Main_Control.connect = connect_opcua;
        GlobalVariables_Main_Control.disconnect = !connect_opcua;
    }

    // ------------------------------------------------------------------------------------------------------------------------//
    // -------------------------------------------------------- FUNCTIONS -----------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//

    // -------------------- Abort Threading Blocks -------------------- //
    void OnApplicationQuit()
    {
        try
        {
            // Stop - threading while
            GlobalVariables_Main_Control.enable_r  = false;

            // Abort threading block {OPCUA -> read data}
            if (opcua_client_r_s_Thread.IsAlive == true && opcua_client_r_Thread[0].IsAlive == true && opcua_client_r_Thread[1].IsAlive == true && opcua_client_r_Thread[2].IsAlive == true
                && opcua_client_r_Thread[3].IsAlive == true && opcua_client_r_Thread[4].IsAlive == true && opcua_client_r_Thread[5].IsAlive == true)
            {
                opcua_client_r_s_Thread.Abort();
                opcua_client_r_Thread[0].Abort();
                opcua_client_r_Thread[1].Abort();
                opcua_client_r_Thread[2].Abort();
                opcua_client_r_Thread[3].Abort();
                opcua_client_r_Thread[4].Abort();
                opcua_client_r_Thread[5].Abort();
            }
        }
        catch (Exception e)
        {
            // Destroy all
            Destroy(this);
        }
        finally
        {
            // Destroy all
            Destroy(this);
        }
    }

    void OPCUa_r_s_thread_function(string ip_adr, string port_adr)
    {
        if (GlobalVariables_Main_Control.enable_r == true)
        {
            // OPCUa client configuration
            client_configuration_r_s = opcua_client_configuration();
            // Establishing communication
            client_end_point_r_s = CoreClientUtils.SelectEndpoint("opc.tcp://" + ip_adr + ":" + port_adr, useSecurity: false, operationTimeout: 2000);
            // Create session
            client_session_r_s = opcua_create_session(client_configuration_r_s, client_end_point_r_s);
        }

        // Threading while {read data}
        while (GlobalVariables_Main_Control.enable_r)
        {

            // ---------- INT ---------- //
            // Camera Control - ID (0 -> default, etc.)
            GlobalVariables_OPC_UA_client.camera_id = int.Parse(client_session_r_s.ReadValue(GlobalVariables_OPC_UA_client.camera_id_node).ToString());

            // Thread Sleep {2 ms}
            Thread.Sleep(2);
        }
    }

    void OPCUa_r0_thread_function(string ip_adr, string port_adr)
    {
        if (GlobalVariables_Main_Control.enable_r == true)
        {
            // OPCUa client configuration
            client_configuration_r[0] = opcua_client_configuration();
            // Establishing communication
            client_end_point_r[0] = CoreClientUtils.SelectEndpoint("opc.tcp://" + ip_adr + ":" + port_adr, useSecurity: false, operationTimeout: 2000);
            // Create session
            client_session_r[0] = opcua_create_session(client_configuration_r[0], client_end_point_r[0]);
        }

        // Threading while {read data}
        while (GlobalVariables_Main_Control.enable_r)
        {

            // ---------- FLOAT ---------- //
            // Position / Velocity - Camera Conveyor
            GlobalVariables_OPC_UA_client.shuttle_x[0] = float.Parse(client_session_r[0].ReadValue(GlobalVariables_OPC_UA_client.shuttle_x_node[0]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_y[0] = float.Parse(client_session_r[0].ReadValue(GlobalVariables_OPC_UA_client.shuttle_y_node[0]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_rot_y[0] = float.Parse(client_session_r[0].ReadValue(GlobalVariables_OPC_UA_client.shuttle_rot_y_node[0]).ToString(), System.Globalization.CultureInfo.InvariantCulture);

            // Thread Sleep {2 ms}
            Thread.Sleep(2);
        }
    }

    void OPCUa_r1_thread_function(string ip_adr, string port_adr)
    {
        if (GlobalVariables_Main_Control.enable_r == true)
        {
            // OPCUa client configuration
            client_configuration_r[1] = opcua_client_configuration();
            // Establishing communication
            client_end_point_r[1] = CoreClientUtils.SelectEndpoint("opc.tcp://" + ip_adr + ":" + port_adr, useSecurity: false, operationTimeout: 2000);
            // Create session
            client_session_r[1] = opcua_create_session(client_configuration_r[1], client_end_point_r[1]);
        }

        // Threading while {read data}
        while (GlobalVariables_Main_Control.enable_r)
        {

            // ---------- FLOAT ---------- //
            // Position / Velocity - Camera Conveyor
            GlobalVariables_OPC_UA_client.shuttle_x[1] = float.Parse(client_session_r[1].ReadValue(GlobalVariables_OPC_UA_client.shuttle_x_node[1]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_y[1] = float.Parse(client_session_r[1].ReadValue(GlobalVariables_OPC_UA_client.shuttle_y_node[1]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_rot_y[1] = float.Parse(client_session_r[1].ReadValue(GlobalVariables_OPC_UA_client.shuttle_rot_y_node[1]).ToString(), System.Globalization.CultureInfo.InvariantCulture);

            // Thread Sleep {2 ms}
            Thread.Sleep(2);
        }
    }

    void OPCUa_r2_thread_function(string ip_adr, string port_adr)
    {
        if (GlobalVariables_Main_Control.enable_r == true)
        {
            // OPCUa client configuration
            client_configuration_r[2] = opcua_client_configuration();
            // Establishing communication
            client_end_point_r[2] = CoreClientUtils.SelectEndpoint("opc.tcp://" + ip_adr + ":" + port_adr, useSecurity: false, operationTimeout: 2000);
            // Create session
            client_session_r[2] = opcua_create_session(client_configuration_r[2], client_end_point_r[2]);
        }

        // Threading while {read data}
        while (GlobalVariables_Main_Control.enable_r)
        {

            // ---------- FLOAT ---------- //
            // Position / Velocity - Camera Conveyor
            GlobalVariables_OPC_UA_client.shuttle_x[2] = float.Parse(client_session_r[2].ReadValue(GlobalVariables_OPC_UA_client.shuttle_x_node[2]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_y[2] = float.Parse(client_session_r[2].ReadValue(GlobalVariables_OPC_UA_client.shuttle_y_node[2]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_rot_y[2] = float.Parse(client_session_r[2].ReadValue(GlobalVariables_OPC_UA_client.shuttle_rot_y_node[2]).ToString(), System.Globalization.CultureInfo.InvariantCulture);

            // Thread Sleep {2 ms}
            Thread.Sleep(2);
        }
    }

    void OPCUa_r3_thread_function(string ip_adr, string port_adr)
    {
        if (GlobalVariables_Main_Control.enable_r == true)
        {
            // OPCUa client configuration
            client_configuration_r[3] = opcua_client_configuration();
            // Establishing communication
            client_end_point_r[3] = CoreClientUtils.SelectEndpoint("opc.tcp://" + ip_adr + ":" + port_adr, useSecurity: false, operationTimeout: 2000);
            // Create session
            client_session_r[3] = opcua_create_session(client_configuration_r[3], client_end_point_r[3]);
        }

        // Threading while {read data}
        while (GlobalVariables_Main_Control.enable_r)
        {

            // ---------- FLOAT ---------- //
            // Position / Velocity - Camera Conveyor
            GlobalVariables_OPC_UA_client.shuttle_x[3] = float.Parse(client_session_r[3].ReadValue(GlobalVariables_OPC_UA_client.shuttle_x_node[3]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_y[3] = float.Parse(client_session_r[3].ReadValue(GlobalVariables_OPC_UA_client.shuttle_y_node[3]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_rot_y[3] = float.Parse(client_session_r[3].ReadValue(GlobalVariables_OPC_UA_client.shuttle_rot_y_node[3]).ToString(), System.Globalization.CultureInfo.InvariantCulture);

            // Thread Sleep {2 ms}
            Thread.Sleep(2);
        }
    }

    void OPCUa_r4_thread_function(string ip_adr, string port_adr)
    {
        if (GlobalVariables_Main_Control.enable_r == true)
        {
            // OPCUa client configuration
            client_configuration_r[4] = opcua_client_configuration();
            // Establishing communication
            client_end_point_r[4] = CoreClientUtils.SelectEndpoint("opc.tcp://" + ip_adr + ":" + port_adr, useSecurity: false, operationTimeout: 2000);
            // Create session
            client_session_r[4] = opcua_create_session(client_configuration_r[4], client_end_point_r[4]);
        }

        // Threading while {read data}
        while (GlobalVariables_Main_Control.enable_r)
        {

            // ---------- FLOAT ---------- //
            // Position / Velocity - Camera Conveyor
            GlobalVariables_OPC_UA_client.shuttle_x[4] = float.Parse(client_session_r[4].ReadValue(GlobalVariables_OPC_UA_client.shuttle_x_node[4]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_y[4] = float.Parse(client_session_r[4].ReadValue(GlobalVariables_OPC_UA_client.shuttle_y_node[4]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_rot_y[4] = float.Parse(client_session_r[4].ReadValue(GlobalVariables_OPC_UA_client.shuttle_rot_y_node[4]).ToString(), System.Globalization.CultureInfo.InvariantCulture);

            // Thread Sleep {2 ms}
            Thread.Sleep(2);
        }
    }
    void OPCUa_r5_thread_function(string ip_adr, string port_adr)
    {
        if (GlobalVariables_Main_Control.enable_r == true)
        {
            // OPCUa client configuration
            client_configuration_r[5] = opcua_client_configuration();
            // Establishing communication
            client_end_point_r[5] = CoreClientUtils.SelectEndpoint("opc.tcp://" + ip_adr + ":" + port_adr, useSecurity: false, operationTimeout: 2000);
            // Create session
            client_session_r[5] = opcua_create_session(client_configuration_r[5], client_end_point_r[5]);
        }

        // Threading while {read data}
        while (GlobalVariables_Main_Control.enable_r)
        {

            // ---------- FLOAT ---------- //
            // Position / Velocity - Camera Conveyor
            GlobalVariables_OPC_UA_client.shuttle_x[5] = float.Parse(client_session_r[5].ReadValue(GlobalVariables_OPC_UA_client.shuttle_x_node[5]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_y[5] = float.Parse(client_session_r[5].ReadValue(GlobalVariables_OPC_UA_client.shuttle_y_node[5]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.shuttle_rot_y[5] = float.Parse(client_session_r[5].ReadValue(GlobalVariables_OPC_UA_client.shuttle_rot_y_node[5]).ToString(), System.Globalization.CultureInfo.InvariantCulture);

            // Thread Sleep {2 ms}
            Thread.Sleep(2);
        }
    }

    // ------------------------ OPCUa Client {Application -> Configuration (STEP 1)} ------------------------//
    ApplicationConfiguration opcua_client_configuration()
    {
        // Configuration OPCUa Client {W/R -> Data}
        var config = new ApplicationConfiguration()
        {
            // Initialization (Name, Uri, etc.)
            ApplicationName = "OPCUa_AS", // OPCUa AS (Automation Studio B&R)
            ApplicationUri = Utils.Format(@"urn:{0}:OPCUa_AS", System.Net.Dns.GetHostName()),
            // Type -> Client
            ApplicationType = ApplicationType.Client,
            SecurityConfiguration = new SecurityConfiguration
            {
                // Security Configuration - Certificate
                ApplicationCertificate = new CertificateIdentifier { StoreType = @"Directory", StorePath = @"%CommonApplicationData%\OPC Foundation\CertificateStores\MachineDefault", SubjectName = Utils.Format(@"CN={0}, DC={1}", "OPCUa_AS", System.Net.Dns.GetHostName()) },
                TrustedIssuerCertificates = new CertificateTrustList { StoreType = @"Directory", StorePath = @"%CommonApplicationData%\OPC Foundation\CertificateStores\UA Certificate Authorities" },
                TrustedPeerCertificates = new CertificateTrustList { StoreType = @"Directory", StorePath = @"%CommonApplicationData%\OPC Foundation\CertificateStores\UA Applications" },
                RejectedCertificateStore = new CertificateTrustList { StoreType = @"Directory", StorePath = @"%CommonApplicationData%\OPC Foundation\CertificateStores\RejectedCertificates" },
                AutoAcceptUntrustedCertificates = true,
                AddAppCertToTrustedStore = true
            },
            TransportConfigurations = new TransportConfigurationCollection(),
            TransportQuotas = new TransportQuotas { OperationTimeout = 2000 },
            ClientConfiguration = new ClientConfiguration { DefaultSessionTimeout = 2000},
            TraceConfiguration = new TraceConfiguration()
        };
        config.Validate(ApplicationType.Client).GetAwaiter().GetResult();
        if (config.SecurityConfiguration.AutoAcceptUntrustedCertificates)
        {
            config.CertificateValidator.CertificateValidation += (s, e) => { e.Accept = (e.Error.StatusCode == StatusCodes.BadCertificateUntrusted); };
        }

        var application = new ApplicationInstance
        {
            ApplicationName = "OPCUa_AS",
            ApplicationType = ApplicationType.Client,
            ApplicationConfiguration = config
        };
        application.CheckApplicationInstanceCertificate(false, 2048).GetAwaiter().GetResult();

        return config;
    }

    // ------------------------ OPCUa Client {Application -> Create Session (STEP 2)} ------------------------//
    Session opcua_create_session(ApplicationConfiguration client_configuration, EndpointDescription client_end_point)
    {
        return Session.Create(client_configuration, new ConfiguredEndpoint(null, client_end_point, EndpointConfiguration.Create(client_configuration)), false, "", 2000, null, null).GetAwaiter().GetResult();
    }
}
