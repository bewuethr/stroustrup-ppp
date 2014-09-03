
//
// This is example code from Chapter 25.4.1 "Unchecked conversions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

class Device_driver;

//------------------------------------------------------------------------------

int main()
{
    Device_driver* p = reinterpret_cast<Device_driver*>(0xffb8);
}

//------------------------------------------------------------------------------
