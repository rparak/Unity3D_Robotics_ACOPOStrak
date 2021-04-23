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
File Name: shuttle_link.cs
****************************************************************************/

// ------------------------------------------------------------------------------------------------------------------------//
// ----------------------------------------------------- LIBRARIES --------------------------------------------------------//
// ------------------------------------------------------------------------------------------------------------------------//

// -------------------- Unity -------------------- //
using UnityEngine;

public class shuttle_link : MonoBehaviour
{
    // -------------------- Int -------------------- //
    public int shuttle_id;
    // -------------------- Vector3 -------------------- //
    private Vector3 initial_position;
    private Vector3 initial_rotation;

    private void Start()
    {
        // Initial position / rotation of the Shuttle link (stuttle_id)
        initial_position = transform.localPosition;
        initial_rotation = transform.localEulerAngles;
    }

    void FixedUpdate()
    {
        // Read position and rotation of the shuttle (index) - OPC UA Server
        transform.localPosition = new Vector3(initial_position.x + GlobalVariables_OPC_UA_client.shuttle_x[shuttle_id] / 1000, initial_position.y, initial_position.z + GlobalVariables_OPC_UA_client.shuttle_y[shuttle_id] / 1000);
        transform.localEulerAngles = new Vector3(initial_rotation.x, initial_rotation.y, initial_rotation.z + GlobalVariables_OPC_UA_client.shuttle_rot_y[shuttle_id]);
    }
    void OnApplicationQuit()
    {
        Destroy(this);
    }
}
