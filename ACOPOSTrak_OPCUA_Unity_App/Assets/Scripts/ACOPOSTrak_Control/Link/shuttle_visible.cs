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
File Name: shuttle_visible.cs
****************************************************************************/

// ------------------------------------------------------------------------------------------------------------------------//
// ----------------------------------------------------- LIBRARIES --------------------------------------------------------//
// ------------------------------------------------------------------------------------------------------------------------//

// -------------------- Unity -------------------- //
using UnityEngine;

public class shuttle_visible : MonoBehaviour
{
    // -------------------- Int -------------------- //
    public int shuttle_id;
    // -------------------- Int -------------------- //
    private MeshRenderer[] object_visibility;

    private void Start()
    {
        object_visibility = GetComponentsInChildren<MeshRenderer>(true);
        mesh_visibility_fce(false);
    }

    void Update()
    {
        if (GlobalVariables_OPC_UA_client.shuttle_x[shuttle_id] != 0.0 && GlobalVariables_OPC_UA_client.shuttle_y[shuttle_id] != 0.0 && GlobalVariables_OPC_UA_client.shuttle_rot_y[shuttle_id] != 0.0)
        {
            mesh_visibility_fce(true);
        }
        else
        {
            mesh_visibility_fce(false); 
        }
    }

    // ------------------------------------------------------------------------------------------------------------------------//
    // -------------------------------------------------------- FUNCTIONS -----------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//
    private void mesh_visibility_fce(bool enableRenderer)
    {

        for (int i = 0; i < object_visibility.Length; i++)
        {
            object_visibility[i].enabled = enableRenderer;
        }
    }

    void OnApplicationQuit()
    {
        Destroy(this);
    }
}
