HAE Service Framework
=====================

Welcom to the HAE Service Framework.

HAE Service Framework provides easy methods to implement HAE controllee and controller applications.


Folder Structure
----------------
<pre>
+---code_template
|   +---interface_template
|   +---vendor_defined_interface_template
|   \---xml
|       +---org.alljoyn.SmartSpaces.Environment
|       +---org.alljoyn.SmartSpaces.Operation
|       \---org.alljoyn.SmartSpaces.UserInterfaceSettings
+---inc
|   \---alljoyn
|       \---hae
|           \---interfaces
|               +---environment
|               +---input
|               \---operation
+---samples
|   +---BaseSample
|   |   +---Controllee
|   |   +---Controller
|   |   \---VendorDefinedInterfaces
|   +---IntegratedController
|   +---TvControllee
|   \---VDIControllee
\---src
|   \---interfaces
|       +---environment
|       +---input
|       \---operation
\---unittest

</pre>

 * cpp/code_template : Generator of HAE interfaces skeleton codes
 * cpp/code_template/xml : Interospection XML files of HAE interfaces
 * cpp/inc/alljoyn/hae : HAE common header files
 * cpp/inc/alljoyn/hae/interfaces : HAE interface-related header files
 * cpp/samples/BaseSample : Base sample for making other device sample
 * cpp/samples/IntegratedController :
   - Integrated controller based on BaseSample controller
   - The current version supports only TV-related interfaces. (Channel, AudioVolume, AudioVideoInput, Hid)
   - Intergrated controller is designed to make it easier to add other interfaces.
 * cpp/samples/TVControllee :
   - Example of hae device composed of Base sample controllee
   - Emulated virtual TV sample. It has 4 interfaces. (Channel, AudioVolume, AudioVideoInput, Hid)


Building
--------
You can build HAE Service Framework using 'scons'.
Please refer to
<a name="AllJoyn build instructions" href="https:///allseenalliance.org/developers/develop/building">AllJoyn Build Instruction </a>
for more details on setting up your environment.

  * Folder structure
<pre>
root-source-dir
    +---core
    |   +---alljoyn
    |   \---ajtcl
    \---services
        +---base
        \---hae
</pre>

  * Build
<pre>
cd root-source-dir/services/hae
scons BINDINGS=cpp WS=off BT=off ICE=off
</pre>

  * Output
<pre>
hae/
    +---bin
    +---inc
    |   \---alljoyn
    |       \---hae
    |           \---interfaces
    |               +---environment
    |               +---input
    |               \---operation
    \---lib
</pre>

    - path : root-source-dir/services/hae/build/$OS/$TARGET_CPU/debug/dist/hae
    - bin : IntegratedController, TvControllee
    - lib : liballjoyn_hae.a, liballjoyn_hae.so
    - inc : header files

Unit Tests
-------
  * Build unit tests
To build the unit tests add a GTEST_DIR='<your local path>/GTEST/googletest' 
parameter to the scons command line.

tests can be found and run from:
<root-source-dir>/services/hae/build/{OS}/{CPU}/{VARIANT}/test/hae/bin

Doxygen
-------
  * Make manual
<pre>
cd root-source-dir/services/hae/cpp/docs
doxygen Doxygen_html
</pre>

  * Make manual in the building step
<pre>
cd root-source-dir/services/hae
scons BINDINGS=cpp WS=off BT=off ICE=off DOCS=html
</pre>

How to add new interface
------------------------
  1. Generate the skeleton codes using make_interface.py script.
  2. Fill the codes for properties, methods and signals in all files generated.

  * Create skeleton codes for new interface
<pre>
cd root-source-dir/services/hae/cpp/code_template
python make_interface.py -n InterfaceName -c CategoryName
(InterfaceName and CategoryName are case sensitive.)
[example]
python make_interface.py -n TargetTemperature -c Environment
Created: ../inc/alljoyn/hae/interfaces/environment/TargetTemperatureInterface.h
Created: ../inc/alljoyn/hae/interfaces/environment/TargetTemperatureIntfControllee.h
Created: ../inc/alljoyn/hae/interfaces/environment/TargetTemperatureIntfControlleeListener.h
Created: ../inc/alljoyn/hae/interfaces/environment/TargetTemperatureIntfController.h
Created: ../inc/alljoyn/hae/interfaces/environment/TargetTemperatureIntfControllerListener.h
Created: ../src/interfaces/environment/TargetTemperatureInterface.cc
Created: ../src/interfaces/environment/TargetTemperatureIntfControlleeImpl.h
Created: ../src/interfaces/environment/TargetTemperatureIntfControlleeImpl.cc
Created: ../src/interfaces/environment/TargetTemperatureIntfControllerImpl.h
Created: ../src/interfaces/environment/TargetTemperatureIntfControllerImpl.cc
</pre>

  * Delete files related new interface
<pre>
cd root-source-dir/services/hae/cpp/code_template
python make_interface.py -n InterfaceName -c Category -d
</pre>

How to add vendor defined interface
------------------------------------
  1. Generate the skeleton codes using make_interface.py script.
  2. Copy all files to your application folder
  3. Fill the codes for properties, methods and signals in all files generated.

  * Create skeleton codes for vendor defined interface
<pre>
cd root-source-dir/services/hae/cpp/code_template
python make_interface.py -n InterfaceName -v
(InterfaceName is case sensitive.)
[example]
python make_interface.py -n Test -v
Created: ./vendor_defined/TestInterface.h
Created: ./vendor_defined/TestIntfControllee.h
Created: ./vendor_defined/TestIntfControlleeListener.h
Created: ./vendor_defined/TestIntfController.h
Created: ./vendor_defined/TestIntfControllerListener.h
Created: ./vendor_defined/TestInterface.cc
Created: ./vendor_defined/TestIntfControlleeImpl.h
Created: ./vendor_defined/TestIntfControlleeImpl.cc
Created: ./vendor_defined/TestIntfControllerImpl.h
Created: ./vendor_defined/TestIntfControllerImpl.cc
</pre>

  * Delete files related vendor defined interface
<pre>
cd root-source-dir/services/hae/cpp/code_template
python make_interface.py -n InterfaceName -v -d
</pre>

Device Emulator
---------------
Device emulator is an emulator for the HAE Service Framework based devices.
You can launch the virtual device using the configuration XML file.

  * Run emulator
<pre>
cd <root-source-dir>/services/hae/build/{OS}/{CPU}/{VARIANT}/dist/hae/bin
./DeviceEmulator config.xml
</pre>

 * Sample config.xml for air conditioner
<pre>
&ltDeviceEmulator&gt
&ltAboutData&gt
&ltAppId&gt000102030405060708090A0B0C0D0E0C&lt/AppId&gt
&ltDefaultLanguage&gten&lt/DefaultLanguage&gt
&ltDeviceName&gtMy Device Name&lt/DeviceName&gt
&ltDeviceName lang = 'es'&gtNombre de mi dispositivo&lt/DeviceName&gt
&ltDeviceId&gtbaddeviceid&lt/DeviceId&gt
&ltAppName&gtMy Application Name&lt/AppName&gt
&ltAppName lang = 'es'&gtMi Nombre de la aplicación&lt/AppName&gt
&ltManufacturer&gtCompany&lt/Manufacturer&gt
&ltManufacturer lang = 'es'&gtEmpresa&lt/Manufacturer&gt
&ltModelNumber&gtWxfy388i&lt/ModelNumber&gt
&ltDescription&gtA detailed description provided by the application.&lt/Description&gt
&ltDescription lang = 'es'&gtUna descripción detallada proporcionada por la aplicación.&lt/Description&gt
&ltDateOfManufacture&gt2014-01-08&lt/DateOfManufacture&gt
&ltSoftwareVersion&gt1.0.0&lt/SoftwareVersion&gt
&ltHardwareVersion&gt1.0.0&lt/HardwareVersion&gt
&ltSupportUrl&gtwww.example.com&lt/SupportUrl&gt
&ltUserDefinedTag&gtCan only accept strings anything other than strings must be done using the AboutData Class SetField method&lt/UserDefinedTag&gt
&ltUserDefinedTag lang='es'&gtSólo se puede aceptar cadenas distintas de cadenas nada debe hacerse utilizando el método AboutData Clase SetField&lt/UserDefinedTag&gt
&ltCountryOfProduction&gtRoom1&lt/CountryOfProduction&gt
&ltLocation&gtRoom1&lt/Location&gt
&ltProductBrand&gtRoom1&lt/ProductBrand&gt
&ltLocation&gtupstairs bedroom&lt/Location&gt
&ltLocation lang='es'&gthabitación del segundo piso&lt/Location&gt
&ltDeviceTypeDescription&gt
&ltTypeDescription&gt
&ltdevice_type&gt5&lt/device_type&gt
&ltobject_path&gt/Hae/AirConditioner&lt/object_path&gt
&lt/TypeDescription&gt
&lt/DeviceTypeDescription&gt
&lt/AboutData&gt
&ltInterfaceList&gt
&ltObject path='/Hae/AirConditioner'&gt
&ltInterface name='org.alljoyn.SmartSpaces.Environment.TargetTemperature'/&gt
&ltInterface name='org.alljoyn.SmartSpaces.Environment.CurrentTemperature'/&gt
&ltInterface name='org.alljoyn.SmartSpaces.Environment.WindDirection'/&gt
&ltInterface name='org.alljoyn.SmartSpaces.Operation.OnControl'/&gt
&ltInterface name='org.alljoyn.SmartSpaces.Operation.OffControl'/&gt
&ltInterface name='org.alljoyn.SmartSpaces.Operation.OnOffStatus'/&gt
&ltInterface name='org.alljoyn.SmartSpaces.Operation.FanSpeedLevel'/&gt
&ltInterface name='org.alljoyn.SmartSpaces.Operation.ClimateControlMode'/&gt
&lt/Object&gt
&lt/InterfaceList&gt
&lt/DeviceEmulator&gt
</pre>
