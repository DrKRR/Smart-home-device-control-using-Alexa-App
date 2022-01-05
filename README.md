# Smart-home-device-control-using-Alexa-App
The project presents hardware, software and instructions to design home automation that paves way to develop a full fledged **D**o **I**t **Y**ourself (DIY) home automation system.  The hardware is designed around tiny NodeMCU ESP8266 board with inexpensive components and software developed in the Arduino environment. Alexa App<img src="https://user-images.githubusercontent.com/93868543/147926210-696c11b4-185c-4bac-aa96-1b68e80eee33.png" width="50" height="30"/>  is used on Mobile to control the home automation system. Alternately, Google Assistant can also be used <img src="https://user-images.githubusercontent.com/93868543/147928681-60e59a9e-781f-425b-be5d-c417176b067e.png" width="50" height="30"/>.
### INTRODUCTION ###
Home automation or domotics refers to automation of a house. Such a system monitors and (or) controls parameters such as climate, lighting, entertainment, electronic gadgets etc. When it comes to home security, it controls access and alarm systems also. In this project, the home appliances are controlled by Alexa app via internet, thus **I**nternet **o**f **T**hings (IoT). Smart home appliances like fan, bulb, cooler etc. works at 115V/230V ac. Care must be exercised during rigging and testing of the hardware, as there is a chance of getting a shock!<br/> In the following, I describe the hardware and software that simulates the smart home project. Neverthless, it paves way to develop a full fledged **DIY** home automation system. Broadly speaking, home automation can be accomplished by two methods: <br/> **Method 1:** using commercially available devices like: Apple Home Kit, Google Nest Hub, Control4, Amazon Alexa echo etc. or <br/> **Method 2:** without using (1), using a microcontroller, SinricPro software and Alexa app. 
<br/> A pictorial representation of these two methods are shown below. 
<p float="middle">
<img src="https://user-images.githubusercontent.com/93868543/148007932-ac7d4546-436f-41f4-a2e3-cba5be309b36.png" width="700" height="350"/>
<img src="https://user-images.githubusercontent.com/93868543/148014830-9ccdd9f9-0f5d-4d65-b617-75fbc0fc79df.png" width="700" height="350"/>
<!---img src="https://user-images.githubusercontent.com/93868543/148013667-492d907f-35f6-4543-9998-940397abac8f.png" width="700" height="350"/---> 
<!---img src="https://user-images.githubusercontent.com/93868543/148009711-a8948e34-7031-4eb4-b26b-b8d448365eaf.png" width="700" height="350"/--->
 </p> </br>
 
In this project, I am explaining the implementation of home automation system using the second method. </br>
### HARDWARE DESCRIPTION ###
#### Components required ####
* NodeMCU ESP8266 Module
* Bread board
* DIP Switch
* Light Emitting Diodes
* Resistors and Jumper wires
* 5V dc source/Power bank <br/>
<p float="middle">
<img src="https://user-images.githubusercontent.com/93868543/147882209-c241e171-3533-427d-926d-61b7058990e5.png" width="200" height="150"/>
<img src="https://user-images.githubusercontent.com/93868543/147898692-0bd91724-eccf-4b94-8c1d-1d51d0c468ec.png" width="150" height="150"/>
<img src="https://user-images.githubusercontent.com/93868543/147899370-4d228ba3-3638-4f2b-8b92-ea948786a3e5.png" width="250" height="200"/>
</p> </br>  
<p float="middle">
<img src="https://user-images.githubusercontent.com/93868543/147899652-833e8be0-8b51-4dd7-b8e3-13fa776bd8ab.png" width="70" height="90"/>
<img src="https://user-images.githubusercontent.com/93868543/147900345-c32a8b87-0fc6-401e-823e-9f58486c8536.png" width="70" height="90"/>
<img src="https://user-images.githubusercontent.com/93868543/147900647-e3bf4bf2-889d-45b6-836b-9e99616de710.png" width="70" height="200"/>
<img src="https://user-images.githubusercontent.com/93868543/147917665-6c059382-578f-45c8-b292-dcd7af60a987.png" width="70" height="90"/>
<img src="https://user-images.githubusercontent.com/93868543/147900950-012edf42-3c61-415c-a501-fff5fa815875.png" width="150" height="200"/>
<img src="https://user-images.githubusercontent.com/93868543/147901282-b6046c91-9ec6-463e-9364-517ac2ce3170.png" width="150" height="200"/>
</p> <br/> 

#### Methodology #####
The hardware described in this project works at 3.3V, and hence no fear of shock. DIP (**D**ual **I**n-line **P**ackage) switches works like ON-OFF switches.  The upper half of the first figure below shows the connection between the NodeMCU ESP8266 module and other components like DIP switches and LEDs. In the lower half of the first figure, circuit design pertaining to relays and bulbs working at 230V is also given. The following second diagram shows the photograph of the completed circuit using the second scheme, i.e., without using Amazon Echo. A detailed hardware description is given in the following YouTube video link. </br>
<p float="middle">
<img src="https://user-images.githubusercontent.com/93868543/147904390-ce4d5424-259e-4eb6-b810-a2eb19a106e9.png" width="300" height="450"/>
<img src="https://user-images.githubusercontent.com/93868543/147904742-7e75668f-d40d-4a66-ad0d-3ec16db3b34a.png" width="300" height="450"/>
</p> </br>

### SOFTWARE DESCRIPTION ###
Software plays an important role in this project.It has the following three parts: 
#### Part-I: #### 
Program development in Arduino environment in order to interface and control LEDs and switches with the digital Input/Output (DIO) pins of the ESP8266 module. Parameters that need to be used in the main program include: 
* (a). WiFi Credentials (Network name, Password) </br>
* (b). APP_KEY and APP_SECRET_CODE </br>
* (c). Device IDs corresponding to the voice control <br/>
The first parameter (a) is user known. The second and third parameters (b and c) needs to obtained from Sinric Pro. 
#### Part-II: ####
