/*=============================================================================
  Copyright (C) 2014 Allied Vision Technologies7.  All Rights Reserved.

  Redistribution of this file, in original or modified form, without
  prior written consent of Allied Vision Technologies is prohibited.

-------------------------------------------------------------------------------

  File:        program.c

  Description: Main entry point of SerialIO example of VimbaC.

-------------------------------------------------------------------------------

  THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF TITLE,
  NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE ARE
  DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/

#include <iostream>

#include <SerialIO.h>

int main( int argc, char* argv[] )
{
    std::cout << "\n";
    std::cout << "///////////////////////////////////\n";
    std::cout << "/// Vimba API Serial IO Example ///\n";
    std::cout << "///////////////////////////////////\n";
    std::cout << "\n";

    if( 3 < argc )
    {
        std::cout << "Usage: SerialIO [CameraID] [ComPort]\n\n";
        std::cout << "Parameters:   CameraID    ID of the camera to use (using first camera if not specified)\n";
        std::cout << "              ComPort     Name of the com port to use (using COM1 if not specified)\n";
    }
    else if( 3 == argc )
    {
        AVT::VmbAPI::Examples::SerialIO::RunTest( (const char*)argv[1], (const char*)argv[2] );
    }
    else
    {
        AVT::VmbAPI::Examples::SerialIO::RunTest( "" , "" );
    }

    std::cout << "\n";
}
