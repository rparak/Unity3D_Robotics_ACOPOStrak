/****************************************************************************
MIT License
Copyright(c) 2020 Roman Parak
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
File Name: camera_position.cs
****************************************************************************/

// ------------------------------------------------------------------------------------------------------------------------//
// ----------------------------------------------------- LIBRARIES --------------------------------------------------------//
// ------------------------------------------------------------------------------------------------------------------------//

// -------------------- Unity -------------------- //
using UnityEngine;

public class camera_position : MonoBehaviour
{
    void Update()
    {
        // Set camera position -> Read from OPC UA server (Mapp View)
        set_camera_position(GlobalVariables_OPC_UA_client.camera_id);
    }

    // ------------------------------------------------------------------------------------------------------------------------//
    // -------------------------------------------------------- FUNCTIONS -----------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//
    void set_camera_position(int camera_id)
    {
        switch (camera_id)
        {
            case 0:
                {
                    // Right -> Camera Position
                    GetComponent<Camera>().transform.localPosition = new Vector3(-0.334f, 2.982f, -2.978f);
                    GetComponent<Camera>().transform.localEulerAngles = new Vector3(15f, -25f, 0f);
                    GetComponent<Camera>().orthographic = false;
                    GetComponent<Camera>().nearClipPlane = 0.3f;
                }
                break;

            case 1:
                {
                    // Left -> Camera Position
                    GetComponent<Camera>().transform.localPosition = new Vector3(-3.032f, 2.982f, -2.978f);
                    GetComponent<Camera>().transform.localEulerAngles = new Vector3(15f, 25f, 0f);
                    GetComponent<Camera>().orthographic = false;
                    GetComponent<Camera>().nearClipPlane = 0.3f;
                }
                break;

            case 2:
                {
                    // Top -> Camera Position
                    GetComponent<Camera>().transform.localPosition = new Vector3(-1.4f, 4.05f, -0.01f);
                    GetComponent<Camera>().transform.localEulerAngles = new Vector3(90f, 0f, 0f);
                    GetComponent<Camera>().orthographic = true;
                    GetComponent<Camera>().orthographicSize = 1.45f;
                    GetComponent<Camera>().nearClipPlane = 0.3f;
                }
                break;

            case 3:
                {
                    // Machine Vision (1) Trak A -> Camera Position
                    GetComponent<Camera>().transform.localPosition = new Vector3(-2.4473f, 1.762f, -1.0775f);
                    GetComponent<Camera>().transform.localEulerAngles = new Vector3(0f, 41f, 0f);
                    GetComponent<Camera>().orthographic  = false;
                    GetComponent<Camera>().nearClipPlane = 0.1f;
                }
                break;

            case 4:
                {
                    // Machine Vision (2) Trak B -> Camera Position
                    GetComponent<Camera>().transform.localPosition = new Vector3(-0.651f, 2.486f, 0.586f);
                    GetComponent<Camera>().transform.localEulerAngles = new Vector3(90f, 0f, 0f);
                    GetComponent<Camera>().orthographic = true;
                    GetComponent<Camera>().orthographicSize = 0.1f;
                    GetComponent<Camera>().nearClipPlane = 0.5f;
                }
                break;
        }
    }
    void OnApplicationQuit()
    {
        Destroy(this);
    }
}
