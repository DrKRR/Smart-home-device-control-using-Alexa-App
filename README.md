# Smart-home-device-control-using-Alexa-App
The project presents hardware, software and instructions to design home automation that paves way to develop a full fledged Do It Yourself (DIY) home automation system.  The hardware is designed around NodeMCU ESP8266 board with inexpensive components and software developed in the Arduino environment. Alexa App is used on Mobile to control the home automation system.
### INTRODUCTION ###
Home automation or domotics refers to automation of a house. Such a system monitors and (or) controls parameters such as climate, lighting, entertainment, electronic gadgets etc. When it comes to home security, it controls access and alarm systems also. In this project, the home appliances are controlled by Alexa app via internet, thus **I**nternet **o**f **T**hings (IoT). Smart home appliances like fan, bulb, cooler etc. works at 115V/230V ac. Care must be exercised during rigging and testing of the hardware, as there is a chance of getting a shock!<br/> In the following, I describe the hardware and software that simulates the smart home project. Neverthless, it paves way to develop a full fledged **DIY** home automation system. Broadly speaking, home automation can be accomplished by two methods: <br/> (i). using commercially available devices like: Apple Home Kit, Google Nest Hub, Control4, Amazon Alexa echo etc. or <br/> (ii). without using (i), using a microcontroller, SinricPro software and Alexa app. In this project, I am explaining the implementation of home automation system using the second method.
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
<img src="https://user-images.githubusercontent.com/93868543/147899652-833e8be0-8b51-4dd7-b8e3-13fa776bd8ab.png" width="90" height="90"/>
<img src="https://user-images.githubusercontent.com/93868543/147900345-c32a8b87-0fc6-401e-823e-9f58486c8536.png" width="90" height="90"/>
<img src="https://user-images.githubusercontent.com/93868543/147900647-e3bf4bf2-889d-45b6-836b-9e99616de710.png" width="90" height="200"/>
<img src="https://user-images.githubusercontent.com/93868543/147900950-012edf42-3c61-415c-a501-fff5fa815875.png" width="150" height="250"/>
<img src="https://user-images.githubusercontent.com/93868543/147901282-b6046c91-9ec6-463e-9364-517ac2ce3170.png" width="150" height="200"/>
</p> </br> 

#### Methodology #####
The hardware described in this project works at 3.3V, and hence no fear of shock. DIP (**D**ual **I**n-line **P**ackage) switches works like ON-OFF switches.  The upper half of the first figure below shows the connection between the NodeMCU ESP8266 module and other components like DIP switches and LEDs. In the lower half of the first figure, circuit design pertaining to relays and bulbs working at 230V is also given. The following second diagram shows the photograph of the completed circuit using the second scheme, i.e., without using Amazon Echo. </br>
<p float="middle">
<img src="https://user-images.githubusercontent.com/93868543/147904390-ce4d5424-259e-4eb6-b810-a2eb19a106e9.png" width="300" height="450"/>
<img src="https://user-images.githubusercontent.com/93868543/147904742-7e75668f-d40d-4a66-ad0d-3ec16db3b34a.png" width="300" height="450"/>
</p> </br>



