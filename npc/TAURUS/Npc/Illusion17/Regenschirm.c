//===== rAthena Script ===========================================|
//= Episode 17.1 Regenschirm                                     =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//================================================================|

lighthalzen,55,278,3	script	Rekenber Guard Oscar#171_light	4_M_LGTGUARD,{
	if(ep_illusion < 11){
		npctalk "Rekenber Guard : This place is restricted.","",bc_self;
		end;
	}
	switch(ep_illusion){
		case 11:
			mes "[ Oscar ]";
			mes "The entrance for the lab has double locks.";
			mes "It's closed from the inside.";
			mes "It will be difficult to get it.";
			next;
			mes "[ Oscar ]";
			mes "I'm not too sure about the locks on the inside, so I don't know yet.";
			mes "Let's secure 'Regenschirm' and find out.";
			mes "Are you ready?";
			next;
			.@md_name$ = "Regenschirm";
			.@party_id = getcharid(1);
			if(!.@party_id){
				mes "[ Oscar ]";
				mes "You'll need to create a party to enter adventurer and...";
				mes "you can't bring anyone other than yourself, it's dangerous inside!";
				close;
			}
			getpartymember .@party_id,3;
			if($@partymembercount != 1){
				mes "[ Oscar ]";
				mes "You can't bring anyone other than yourself, it's dangerous inside!";
				close;
			}
			.@party_name$ = getpartyname(.@party_id);
			switch(select("Generate Regenschirm.:Enter Regenschirm")){
				case 1:
					switch(instance_create(.@md_name$)){
						case -1:
							mes "[ Oscar ]";
							mes "^0000CD"+.@md_name$+" ^000000 - Reservation Failed!";
							mes "Unknown Error Has Occurred.";
							end;
							
						case -2:
							mes "[ Oscar ]";
							mes "- You need a party to enter this memorial dungeon.";
							end;
							
						case -3:
							mes "[ Oscar ]";
							mes "It seems you already have an instance. Please cancel it before proceeding.";
							end;
							
						case -4:
							mes "[ Oscar ]";
							mes "Try to create again later.";
							end;
							
						default:
							mes "[ Oscar ]";
							mes "If you're ready, please enter.";
							mes "The locks on the inside will be handled by Ashley.";
							end;
					}
					
				case 2:
					switch(instance_enter(.@md_name$)){
						case IE_OTHER:
							mes "An unknown error has occurred.";
							end;
							
						case IE_NOINSTANCE:
							mes "^ff0000Character doesn't have an instance reserved.^000000";
							end;
							
						case IE_OK:
							mapannounce "lighthalzen", strcharinfo(0) + " of the party, "+ .@party_name$ +", is entering the " + .@md_name$ + ".", bc_map, "0x00FF99";
							end;
					}	
			}
			
		case 12:
			mes "[ Oscar ]";
			mes "You have a message from Tess back at the Cat on Bullet.";
			mes "He'll see you soon.";
			close;
	}	
		
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 11");
end;
}

1@rgsr,1,1,0	script	#171_rgsr_control	HIDDEN_WARP_NPC,{
OnInstanceInit:
	set_instance_var("map$",instance_mapname("1@rgsr"));
	instance_enable("Researcher#rgsr_ev_0",false);
	instance_enable("Access Controller#rgsr",false);
	instance_enable("#rgsr_touch_mob_0",false);
	instance_enable("#rgsr_touch_mob_1",false);
	instance_enable("#rgsr_warp_0",false);
	instance_enable("Erst#rgsr",false);
	instance_enable("Rebellion Crew#rgsr_dum01",false);
	instance_enable("Ashley#rgsr3",false);
	instance_enable("Gonie#rgsr",false);
	instance_enable("Erst#rgsr2",false);
	instance_enable("Central Room#rgsr",false);
	instance_enable("Restrained Specimen#rgsr",false);
	instance_enable("Control Device#rgsr0",false);
	instance_enable("Control Device#rgsr1",false);
	instance_enable("Control Device#rgsr2",false);
	instance_enable("Control Device#rgsr3",false);
	instance_enable("Ashley#rgsr4",false);
end;

OnEvent01:
	instance_enable("#rgsr_touch_mob_0",true);
	instance_enable("#rgsr_touch_mob_1",true);
	instance_event("#rgsr_mob_1","OnSummon",false);
end;

OnEvent02:
	instance_enable("#rgsr_warp_0",true);
	instance_event("#rgsr_mob_2","OnSummon",false);
end;

OnEvent03:
	instance_enable("Restrained Specimen#rgsr",true);
	instance_enable("Control Device#rgsr0",true);
	instance_enable("Control Device#rgsr1",true);
	instance_enable("Control Device#rgsr2",true);
	instance_enable("Control Device#rgsr3",true);
end;

OnEvent04:
	set_instance_var("rgsr",14);
	instance_event("#rgsr_boss","OnSummon",false);
end;
}

1@rgsr,123,42,5	script	Oscar#rgsr	4_M_LGTGUARD,{
	mes "[ Oscar ]";
	mes "The captain sneaked in the control panel room.";
	mes "Move quietly.";
	close;
}

1@rgsr,131,58,3	script	Ashley#rgsr	4_EP17_AS,{
	.@map$ = get_instance_var("map$");
	cutin "ep171_as02",1;
	mes "[ Ashley ]";
	mes "The door is normally locked with the security system, so I have to stay there and work with the controller.";
	mes "As you can see most of the entrances have been blocked already.";
	mes "Hi";
	next;
	mes "[ Ashley ]";
	mes "It will take some time to go through them one by one.";
	mes "I'll keep helping you through the intercom.";
	next;
	mes "[ Ashley ]";
	mes "You'll have to go through the restaurant to reach the hallway.";
	mes "Erst will be performing the operation alone.";
	next;
	mes "[ Ashley ]";
	mes "If there's a disturbance, Erst may have caused it. So please check out with her before continuing.";
	next;
	mes "[ Ashley ]";
	mes "You should go now adventurer. I'll keep working on securing the security controller.";
	mes "There may be researchers detained inside.";
	next;
	mes "[ Ashley ]";
	mes "Please consider their safety first.";
	mes "Now go ahead.";
	close2;
	if(!get_instance_var("rgsr")){
		set_instance_var("rgsr",1);
		instance_event("#171_rgsr_control","OnEvent01",false);
	}
	warp .@map$,127,67;
	end;
}

1@rgsr,60,138,0	script	Access Controller#rgsr	4_ENERGY_WHITE,{
	.@var = get_instance_var("rgsr");
	instance_enable("Researcher#rgsr_ev_0",true);
	if(.@var == 2){
		set_instance_var("rgsr",3);
		npctalk "Communication Requested.";
		sleep2 2750;
		npctalk "Analysing Signal.";
		sleep2 2750;
		npctalk "Activating Voice Transmission...";
		sleep2 2750;
		npctalk "Are you connected? It's Ashley.";
		sleep2 2750;
		npctalk "I have gained control over some of the security system, but I haven't gained full access yet.";
		sleep2 2750;
		npctalk "Unless there is a big disturbance, the alarm or security devices won't work.";
		sleep2 2750;
		npctalk "I think you should open this door to open the hallway.";
		sleep2 2750;
		npctalk "Ask a Detained Researcher to put their hand on the device.";
		sleep2 2750;
		npctalk "...*Zap*....";
		sleep2 2750;
		npctalk "Voice Transmission Ended.";
		sleep2 2750;
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),true);
		npctalk "Researcher : Do you mind If I open the door?",instance_npcname("Researcher#rgsr_ev_0");
		set_instance_var("rgsr",4);
	}
	end;
}

1@rgsr,59,132,7	script	Researcher#rgsr_ev_0	4_M_NFMAN,{
	.@var = get_instance_var("rgsr");
	.@var2 = get_instance_var("activate");
	if(.@var == 4 && .@var2 == 0){
		set_instance_var("activate",1);
		mes "[ Researcher ]";
		mes "The biometric scan is still operational, I'll be staying here to keep the door open.";
		mes "If you're in a hurry, please go...";
		dispbottom "Control : Identity confirmed.";
		instance_event("#171_rgsr_control","OnEvent02",false);
		close2;
		sleep2 800;
		npctalk "Researcher : ...huh... what the hell is this...";
		end;
	}
}

1@rgsr,36,211,3	script	Erst#rgsr	4_F_ESTLOVELOY,{
	.@var = get_instance_var("rgsr");
	if(.@var < 8){
		cutin "ep162_est03",2;
		mes "[ Erst ]";
		mes "Are you the one who removed the poison gas outside?";
		mes "You arrived at a good time.";
		mes "Because of the gas, the door was forcibly locked down!";
		next;
		cutin "ep162_est01",2;
		mes "[ Erst ]";
		mes "It takes time for Ashley to come hack the controller and release the gas.";
		mes "I was going to do it myself.";
		next;
		cutin "ep162_est02",2;
		mes "[ Erst ]";
		mes "The guards here were wearing the same clothes as those Heart Hunters we saw before.";
		mes "I don't think I can save all the researchers alone.";
		next;
		mes "[ Erst ]";
		mes "It seems we've gathered most of them here already.";
		mes "Let's organize our next strategy.";
		next;
		cutin "ep162_est01",2;
		mes "[ Erst ]";
		mes "There are laboratories on the other side and it's likely to be a mess.";
		mes "I wonder if there will be a big fight.";
		next;
		mes "[ Erst ]";
		mes "From now on the Rebellion Special Forces will prioritize on rescuing the Detained Researchers.";
		mes "If you get it, move quickly!";
		next;
		mes "[ Erst ]";
		mes "Okay, adventurer, find a communication device and get in contact with Ashley, using code 0315.";
		next;
		mes "[ Erst ]";
		mes "You have to open the entrance of the private labs.";
		if(.@var == 4)
			set_instance_var("rgsr",5);
		close3;
	}
	cutin "ep162_est02",2;
	mes "[ Erst ]";
	mes "Huh. We'll focus on rescuing the hostages first.";
	mes "Look for the Security Guard's room that Ashley talked about.";		
	close3;	
}

1@rgsr,26,219,0	script	Access Controller#rgsr2	4_ENERGY_WHITE,{
	.@var = get_instance_var("rgsr");
	if(.@var < 5){
		mes "Code is inactive.";
		mes "The communication has been terminated.";
		close;
	}
	if(.@var == 5){
		mes "Voice Transmission Connected.";
		close2;
		set_instance_var("rgsr",6);
		npctalk "Waiting for communication response...";
		sleep2 2750;
		npctalk "Ashley : Commander Erst? We closed the hall lock, but what is the problem?";
		sleep2 2750;
		npctalk "Ashley : Oh you're the adventurer. I will give you the report. I have not fully taken over the security controller system yet.";
		sleep2 2750;
		npctalk "Ashley : It seems it will take some time, but I've taken control of most of the monitoring modules.";
		sleep2 2750;
		npctalk "Ashley : Most of the enemy troops were in the lobby and the resting area, so the lab area is less guarded.";
		sleep2 2750;
		npctalk "Ashley : However, in order to secure the central control room, you have to go through the Guard's Room where many test subjects were detected.";
		sleep2 2750;
		npctalk "Ashley : The priority should be to secure the laboratories and then the Guard Room.... *click*";
		sleep2 2000;
		npctalk "Erst : Eh, what was that?",instance_npcname("Erst#rgsr");
		set_instance_var("rgsr",7);
		end;
	}
	if(.@var < 7)
		end;
	else {
		mes "Code is inactive.";
		mes "The communication has been terminated.";
		close;
	}
}

1@rgsr,235,44,5	script	Ashley#rgsr2	4_EP17_AS,{
	.@var = get_instance_var("rgsr");
	if(.@var == 7){
		for(.@i = 0; .@i < 3; .@i++){
			if(!get_instance_var("rescued[" + .@i + "]"))
				.@miss++;
		}
		if(.@miss){
			cutin "ep171_as02",2;
			mes "[ Ashley ]";
			mes "Hey, Did you check all the labs yet?";
			mes "Please check if there are still Detained Researchers.";
			close3;
		}
		cutin "ep171_as02",1;
		mes "[ Ashley ]";
		mes "The spare Master Key still remains.";
		mes "Without it, I wouldn't have been able to control over the security systems. Are you okay?";
		next;
		mes "[ Ashley ]";
		mes "Now you only need to check the Central Room.";
		mes "Did you say Heart Hunters?";
		mes "The traitors from Schlein have already escaped.";
		next;
		mes "[ Ashley ]";
		mes "We've got our focus on that room.";
		mes "That's the main idea.";
		mes "Where is Erst?";
		next;
		cutin "16go_01",0;
		mes "[ Gonie ]";
		mes "... ... ...";
		next;
		cutin "ep171_as02",1;
		mes "[ Ashley ]";
		mes "You have to keep looking for all the Researchers?";
		mes "That's necessary, I understand.";
		next;
		mes "[ Ashley ]";
		mes "Adventurer, we head to the Central Room.";
		mes "Meet me over there.";
		close2;
		cutin "",255;
		instance_enable("Central Room#rgsr",true);
		set_instance_var("rgsr",8);
		instance_enable("#rgsr_mob_2",false);
		end;
	}
	cutin "ep171_as02",1;
	mes "[ Ashley ]";
	mes "Adventurer, we head to the Central Room.";
	mes "Meet me over there.";
	close3;
}

1@rgsr,235,143,5	script	Detained Researcher#rgsr_q01	4_F_SCIENCE,{
	.@var = get_instance_var("rescued[0]");
	if(!.@var){
		mes "[ Researcher ]";
		mes "My... my search... materials...";
		mes "They took it all!";
		mes "They took everything!";
		next;
		cutin "16go_01",0;
		mes "[ Gonie ]";
		mes "... ... ...";
		next;
		cutin "",255;
		npctalk "I'm going to live! Thank you!";
		mes "Oh, you're here to protect me?";
		mes "I'll go with you, thank you!";
		next;
		mes "[ Researcher ]";
		mes "Oh, you're there to protect me?";
		mes "I'll go with you, thank you!";
		set_instance_var("rescued[0]",1);
		close2;
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
	}
	end;
}

1@rgsr,237,108,3	script	Detained Researcher#rgsr_q02	4_LGTSCIENCE,{
	.@var = get_instance_var("rescued[1]");
	if(!.@var){
		mes "[ Researcher ]";
		mes "I thought they kicked out all the crazy guy...";
		mes "I hit the back of my head like this.";
		mes "Tsk.";
		next;
		mes "[ Researcher ]";
		mes "Are you here to save us?";
		mes "Get me out of here!";
		mes "We couldn't flee because they put poisonous gas outside the doors!";
		next;
		mes "[ Researcher ]";
		mes "Yeah, I know a little bit about the Heart Hunters, I will tell you everything!";
		next;
		cutin "ep162_est02",2;
		mes "[ Erst ]";
		mes "Ah? Do you have more information to share?";
		mes "Do you want to go outside and talk about it calmly with me?";
		next;
		cutin "ep162_est01",2;
		mes "[ Erst ]";
		mes "I'll take this guy out of here and you look at the other rooms.";
		set_instance_var("rescued[1]",1);
		close2;
		cutin "",255;
		instance_hide(strnpcinfo(0),true);
		instance_enable(strnpcinfo(0),false);
	}
	end;
}

1@rgsr,237,71,3	script	Detained Researcher#rgsr_q03	4_F_FRUIT,{
	.@var = get_instance_var("rescued[2]");
	if(!.@var){
		mes "[ Researcher ]";
		mes "Please help me!";
		mes "I worked a lot and I'm not getting paid!";
		next;
		mes "[ Researcher ]";
		mes "Schlein, where is Schlein?";
		mes "He's a traitor!";
		mes "I've seen it with my own eyes, he just killed the guards...";
		next;
		select("Calm down.");
		mes "[ Researcher ]";
		mes "Is it safe now?";
		mes "I'm glad when I was hired at Rekenber, but what the hell is going with such a big company...";
		next;
		mes "[ Researcher ]";
		mes "Say what? The Rebellions are coming to save us?";
		mes "Can't I just run away with you instead?";
		next;
		mes "[ Researcher ]";
		mes "Oh... you're part of the recon team?";
		mes "Alright. I'll wait for the rescue team.";
		mes "Many people escaped by breaking the windows and ran away..";
		next;
		mes "[ Researcher ]";
		mes "Oh you already know.";
		mes "Okay. I'll be quiet now and wait.";
		mes "Your uniform is really cool though.";
		set_instance_var("rescued[2]",1);
		end;
	}
	mes "[ Researcher ]";
	mes "I know. I know.";
	mes "If I wait here, will the Rebellions come and save me?";
	mes "I'll be fine then.";
	next;
	mes "[ Researcher ]";
	mes "But again, your uniform is really cool.";
	close;
}

1@rgsr,241,51,0	script	Scattered Documents#rgsr	4_ENERGY_BLUE,{
	if(isbegin_quest(7863) == 0){
		mes "This is the list of the Enterprise security teams.";
		mes "Some have circles around them... others are crossed out.";
		next;
		cutin "ep171_as01",2;
		mes "[ Ashley ]";
		mes "The ones circled are probably those who accepted to be recruited...";
		mes "My team is the one with a X marked next to it.";
		next;
		mes "[ Ashley ]";
		mes "It's a mercenary contract...";
		mes "There's a rough plan for the day of the raid.";
		mes "I can't believe it came to this...";
		next;
		mes "[ Ashley ]";
		mes "This is meant to provoke me.";
		mes "It won't work this time. I'll track this to the end.";
		next;
		mes "[ Ashley ]";
		mes "I'd better take it back to Tess and analyze it.";
		setquest 7863;
		close3;
	}
	mes "I've already got the data here.";
	mes "There's nothing else to see here.";
	close;

OnInstanceInit:
	questinfo(QTYPE_CLICKME,QMARK_YELLOW,"isbegin_quest(7863) == 0");
end;
}

1@rgsr,125,157,0	script	Central Room#rgsr	4_ENERGY_BLUE,{
	.@var = get_instance_var("rgsr");
	if(.@var == 8){
		set_instance_var("rgsr",9);
		instance_enable("Ashley#rgsr3",true);
		instance_enable("Gonie#rgsr",true);
		instance_enable("Erst#rgsr2",true);
		npctalk "Am I late?",instance_npcname("Ashley#rgsr3");
		sleep2 1800;
		npctalk "No you arrived just in time.",instance_npcname("Erst#rgsr2");
		end;
	}
	mes "The device does not work.";
	end;	
}

1@rgsr,128,157,3	script	Ashley#rgsr3	4_EP17_AS,{
	.@var = get_instance_var("rgsr");
	.@map$ = get_instance_var("map$");
	if(.@var > 13)
		end;
	if(.@var == 9){
		set_instance_var("rgsr",10);
		.@ashley$ = instance_npcname("Ashley#rgsr3");
		.@gonie$ = instance_npcname("Gonie#rgsr");
		.@erst$ = instance_npcname("Erst#rgsr2");
		npctalk "Ashley : The Central Room seems to be empty. I'll go in and check it out.",.@ashley$;
		sleep2 3000;
		npctalk "Erst : I'll go ahead and take the researchers out of here. Will that be okay?",.@erst$;
		sleep2 3000;
		npctalk "Ashley : Yes. Nothing else is being detected on the system. With our progres so far, the enemies have all been restrained.",.@ashley$;
		sleep2 3000;
		npctalk "Erst : What are you scared of something else? I'm going back already!",.@erst$;
		sleep2 3000;
		npctalk "Gonie : ... Me too.",.@gonie$;
		sleep2 3000;
		npctalk "Erst : There were couple of researchers left in the labs, I'll go bring them along. I'll be waiting.",.@erst$;
		sleep2 3000;
		npctalk "Erst : Alright, Gonie. You go to the main lobby first and secure the road. I'll take the others at the conference room.",.@erst$;
		sleep2 3000;
		npctalk "Gonie : *Nods*",.@gonie$;
		sleep2 3000;
		instance_enable("Gonie#rgsr",false);
		instance_enable("Erst#rgsr2",false);
		npctalk "Ashley : So adventurer, let's check out the Central Room.",.@ashley$;
		set_instance_var("rgsr",11);
		end;		
	}
	cutin "ep171_as02",1;
	mes "[ Ashley ]";
	mes "That's the Central Room right ahead.";
	next;
	if(select("Enter.:Wait.") == 2){
		mes "[ Ashley ]";
		mes "Please speak to me when you're ready.";
		mes "I don't know why, but it's tightly closed;. It takes some time to maintain access.";
		next;
		mes "[ Ashley ]";
		mes "As confirmed by the security system, nothing is being detected on the inside...";
		mes "I still want to confirm inside the room regardless.";
		close3;
	}
	mes "[ Ashley ]";
	mes "First I'll need to disable the auto-locking mechanism, and then I'll follow right away.";
	if(.@var == 11){
		set_instance_var("rgsr",12);
		instance_event("#171_rgsr_control","OnEvent03",false);
	}
	close2;
	cutin "",255;
	warp .@map$,126,164;
	end;
}

1@rgsr,124,152,5	script	Gonie#rgsr	4_M_GONY,{
	cutin "16go_01",0;
	mes "[ Gonie ]";
	mes "... ... ...";
	close3;
}

1@rgsr,125,154,5	script	Erst#rgsr2	4_F_ESTLOVELOY,{
	cutin "ep162_est01",2;
	mes "[ Erst ]";
	mes "I don't believe there are any enemies left inside, I'm going to pull out.";
	mes "Just check the Central Room and then get out.";
	close3;
}

1@rgsr,125,188,3	script	Restrained Specimen#rgsr	20353,2,3,{
	.@var = get_instance_var("rgsr");
	.@map$ = get_instance_var("map$");
	if(.@var == 12){
		specialeffect EF_RED_HIT;
		specialeffect EF_BEGINSPELL3;
		npctalk "Do... do not... come close to me...!! Huh, my head... it hurts...";
		mapannounce .@map$,"Do... do not... come close to me...!! Huh, my head... it hurts...",bc_map,0x00FF00;
		set_instance_var("rgsr",13);
	}
	end;
	
OnFail:
	.@map$ = get_instance_var("map$");
	specialeffect EF_FREEZE;
	npctalk "Awesome-!! That's it... What did you do!!";
	mapannounce .@map$,"Awesome-!! That's it... What did you do!!",bc_map,0x00FF00;
end;
}

1@rgsr,144,180,0	script	Control Device#rgsr0	4_ENERGY_BLUE,{
	.@var = get_instance_var("rgsr");
	.@map$ = get_instance_var("map$");
	if(.@var < 13){
		mes "This device has an unknown purpose.";
		mes "There are four buttons in the room.";
		close;
	}
	.@index = atoi(replacestr(strnpcinfo(2),"rgsr",""));
	if(.@index > 0){
		if(!get_instance_var("rsgr_c["+(.@index - 1)+"]")){
			mes "This device has an unknown purpose.";
			mes "There are four buttons in the room.";
			next;
			select("Press the button.");
			instance_event("Restrained Specimen#rgsr","OnFail",false);
			end;
		}
	}
	if(!get_instance_var("rsgr_c["+.@index+"]")){
		switch(.@index){
			case 0: .@answer = 2; .@string$ = "three phases"; break;
			case 1: .@answer = 1; .@string$ = "two phases"; break;
			case 2: .@answer = 4; .@string$ = "one phase"; break;
			case 3: .@answer = 3; break;
		}
		mes "This device has an unknown purpose.";
		mes "There are four buttons in the room.";
		next;
		.@s = select("Red Button.:Blue Button.:White Button.:Yellow Button.");
		if(.@s != .@answer)
			instance_event("Restrained Specimen#rgsr","OnFail",false);
		else {
			specialeffect EF_BEGINSPELL3,AREA,instance_npcname("Restrained Specimen#rgsr");
			if(.@index < 3){
				mapannounce .@map$,"Gravity control adjustment... completed... There are " + .@string$ +" remaining.",bc_map,0x0D98BA;
				set_instance_var("rsgr_c["+.@index+"]",1);
			} else {
				set_instance_var("rsgr_c["+.@index+"]",1);
				mapannounce .@map$,"Gravity control adjustment... completed... Restraints have been disengaged.",bc_map,0x0D98BA;
				sleep2 2500;
				instance_event("#171_rgsr_control","OnEvent04",false);
			}
		}
		end;
	}
	mes "This device has already been activated.";
	close;		
}

1@rgsr,108,168,0	duplicate(Control Device#rgsr0)	Control Device#rgsr1	4_ENERGY_RED
1@rgsr,114,191,0	duplicate(Control Device#rgsr0)	Control Device#rgsr2	4_ENERGY_WHITE
1@rgsr,143,168,0	duplicate(Control Device#rgsr0)	Control Device#rgsr3	4_ENERGY_YELLOW


1@rgsr,127,164,3	script	Ashley#rgsr4	4_EP17_AS,{
	cutin "ep171_as01",2;
	mes "[ Ashley ]";
	mes "Erst has handled everything else on the inside.";
	mes "Sorry for not being able to help you at all.";
	next;
	mes "[ Ashley ]";
	mes "Let's go back to Einbroch.";
	mes "I'll... I'll go to my office and join you.";
	next;
	switch(select("Move to Einbroch.:Move to Lighthalzen.:Do not exit.")){
		case 1:
			mes "[ Ashley ]";
			mes "We're going to wait for you in the Cat on Bullet.";
			mes "Please head there and meet us in the headquarters.";
			close2;
			ep_illusion = 12;
			warp "einbroch",301,324;
			instance_destroy();
			end;
			
		case 2:
			mes "[ Ashley ]";
			mes "We're going to wait for you in the Cat on Bullet.";
			mes "Please head there and meet us in the headquarters.";
			close2;
			ep_illusion = 12;
			warp "lighthalzen",54,272;
			instance_destroy();
			end;
			
		case 3:
			cutin "ep171_as02",2;
			mes "[ Ashley ]";
			mes "Do you have anything else to investigate?";
			mes "I'll wait  here.";
			close3;
	}
}


//= Monster
1@rgsr,1,1,0	script	#rgsr_mob_1	HIDDEN_WARP_NPC,{
OnSummon:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	setarray .@xy,
	153,80,155,81,154,82, //= Bottom Right
	138,85,136,87,138,89, //= Center Right
	152,94,152,98,153,98, //= Stairs Right
	145,114,151,114,156,114, //= Top Right
	97,114,102,114,107,114, //= Top Left
	102,98,101,96,101,95, //= Stairs Left
	116,88,118,88,121,87, //= Center Left
	117,101,117,101,117,102, //= Center Top
	93,66,93,67,94,68, //= Bottom Door
	58,65,56,57,44,59,31,53,15,55, //= Bottom Room
	59,94,48,98,53,103,36,110,33,126,46,132,55,131; //= Upper Room
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 2)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"Special Guard",3627,1,.@event$;
end;

OnMobKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnMobKill";
	if(!mobcount(.@map$,.@event$)){
		set_instance_var("rgsr",2);
		instance_enable(strnpcinfo(0),false);
		instance_enable("Access Controller#rgsr",true);
	}
end;
}

1@rgsr,1,1,0	script	#rgsr_mob_2	HIDDEN_WARP_NPC,{
OnSummon:
	.@map$ = get_instance_var("map$");
	setarray .@xy,102,137,104,136,104,135,126,139,138,137,139,134,137,133,151,135,150,136,151,137,85,151,82,215,84,216,84,218,107,216;
	setarray .@left_xy,85,170,54,186,55,183,58,181,59,186,62,183,62,216,59,214,56,217,54,214,52,217;
	setarray .@right_xy,167,136,167,135,168,135,208,138,208,134,203,138,200,134,187,123,188,
	123,187,122,186,108,188,107,186,105,196,106,203,109,205,105,208,109,187,92,186,90,188,91,
	187,69,187,67,188,67,201,74,202,77,207,76,211,74,187,48,188,45,186,46,197,45,202,45,208,42,211,42;
	setarray .@top_xy,169,217,169,214,172,217,172,214,176,217,176,214,180,217,180,214,184,217,184,214,167,204,168,203,168,203,167,176,167,176,166,175;
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 2)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"Special Guard",3627,1;
	for(.@i = 0; .@i < getarraysize(.@left_xy); .@i += 2)
		monster .@map$,.@left_xy[.@i],.@left_xy[.@i+1],"Poisonous Gas",20352,1,instance_npcname(strnpcinfo(0))+"::OnLeftKill";
	for(.@i = 0; .@i < getarraysize(.@right_xy); .@i += 2)
		monster .@map$,.@right_xy[.@i],.@right_xy[.@i+1],"Poisonous Gas",20352,1,instance_npcname(strnpcinfo(0))+"::OnRightKill";
	for(.@i = 0; .@i < getarraysize(.@top_xy); .@i += 2)
		monster .@map$,.@top_xy[.@i],.@top_xy[.@i+1],"Poisonous Gas",20352,1,instance_npcname(strnpcinfo(0))+"::OnTopKill";
	end;
	
OnLeftKill:
	.@map$ = get_instance_var("map$");
	.@event$ = instance_npcname(strnpcinfo(0))+"::OnLeftKill";
	if(!mobcount(.@map$,.@event$)){
		mapannounce .@map$,"Erst : Who is it? Are you Ashley? Are you the adventurer?",bc_map,0x0D98BA;
		instance_enable("Erst#rgsr",true);
		instance_enable("Rebellion Crew#rgsr_dum01",true);
	}
end;

OnRightKill:
OnTopKill:
end;
}

1@rgsr,1,1,0	script	#rgsr_boss	HIDDEN_WARP_NPC,{
OnSummon:
	.@map$ = get_instance_var("map$");
	mapannounce .@map$,"Ahahaha.. ahahaha... I'll kill you all!!!!",bc_map,0x00FF00;
	sleep 2000;
	mapannounce .@map$,"Ashley : What is going on? *click* The lock is...!!",bc_map;
	sleep 2000;
	mapannounce .@map$,"I'm not a defect! I'm not a monster!",bc_map,0x00FF00;
	specialeffect EF_LORD,AREA,instance_npcname("Restrained Specimen#rgsr");
	instance_hide("Restrained Specimen#rgsr",true);
	instance_enable("Restrained Specimen#rgsr",false);
	monster .@map$,125,188,"Failed Specimen",20353,1,instance_npcname(strnpcinfo(0))+"::OnBossKill";
	end;
	
OnBossKill:
	instance_hide("Ashley#rgsr3",true);
	instance_enable("Ashley#rgsr3",false);	
	instance_enable("Ashley#rgsr4",true);
	instance_enable(strnpcinfo(0),false);
end;
}


1@rgsr,94,68,5	script	#rgsr_touch_mob_0	3622,4,6,{
	end;
	
OnTouch:
	instance_hide(strnpcinfo(0),true);
	instance_enable(strnpcinfo(0),false);
	.@v = atoi(replacestr(strnpcinfo(2),"rgsr_touch_mob_",""));
	if(!.@v)
		setarray .@xy,98,66,94,68,95,70,92,68;
	else
		setarray .@xy,91,91,91,93,95,93,94,97,97,92;
	.@map$ = get_instance_var("map$");
	for(.@i = 0; .@i < getarraysize(.@xy); .@i += 2)
		monster .@map$,.@xy[.@i],.@xy[.@i+1],"Special Guard",3622,1;	
end;
}

1@rgsr,95,93,5	duplicate(#rgsr_touch_mob_0)	#rgsr_touch_mob_1	3622,4,6

//= Warp/Other
1@rgsr,59,136,0	script	#rgsr_warp_0	WARPNPC,1,2,{
	end;
	
OnTouch:
	.@map$ = get_instance_var("map$");
	warp .@map$,66,136;
end;
}

1@rgsr,51,184,0	script	#rgsr_warp_1	WARPNPC,1,2,{
	end;
	
OnTouch:
	.@event$ = instance_npcname("#rgsr_mob_2")+"::OnLeftKill";
	.@map$ = get_instance_var("map$");
	if(mobcount(.@map$,.@event$)){
		dispbottom "Voice Behind Door : Who's outside? exterminate that strange poison gas!!";
		end;
	}
	switch(atoi(replacestr(strnpcinfo(2),"rgsr_warp_",""))){
		case 1: warp .@map$,46,184; break;
		case 2:	warp .@map$,46,216; break;
		case 3: warp .@map$,54,184; break;
		case 4: warp .@map$,54,216; break;
	}
end;
}

1@rgsr,51,216,0	duplicate(#rgsr_warp_1)	#rgsr_warp_2	WARPNPC,1,2
1@rgsr,49,184,0	duplicate(#rgsr_warp_1)	#rgsr_warp_3	WARPNPC,1,2
1@rgsr,49,216,0	duplicate(#rgsr_warp_1)	#rgsr_warp_4	WARPNPC,1,2

1@rgsr,186,216,0	script	#rgsr_warp_5	WARPNPC,1,2,{
	.@event$ = instance_npcname("#rgsr_mob_2")+"::OnTopKill";
	.@map$ = get_instance_var("map$");
	if(mobcount(.@map$,.@event$)){
		mes "An unknown entity has been detected. Access Denied.";
		end;
	}
	switch(atoi(replacestr(strnpcinfo(2),"rgsr_warp_",""))){
		case 5: warp .@map$,191,216; break;
		case 6: warp .@map$,183,216; break;
	}
end;
}

1@rgsr,188,216,0	duplicate(#rgsr_warp_5)	#rgsr_warp_6	WARPNPC,1,2

1@rgsr,214,136,0	script	#rgsr_warp_7	WARPNPC,1,2,{
	.@event$ = instance_npcname("#rgsr_mob_2")+"::OnRightKill";
	.@map$ = get_instance_var("map$");
	if(mobcount(.@map$,.@event$) > 0 || get_instance_var("rgsr") < 7){
		mes "An unknown entity has been detected. Access Denied.";
		end;
	}
	switch(atoi(replacestr(strnpcinfo(2),"rgsr_warp_",""))){
		case 7: warp .@map$,219,136; break;
		case 8: warp .@map$,211,136; break;
		case 9: warp .@map$,219,108; break;
		case 10: warp .@map$,211,108; break;
		case 11: warp .@map$,219,76; break;
		case 12: warp .@map$,211,76; break;
		case 13: warp .@map$,219,44; break;
		case 14:  warp .@map$,211,44; break;
	}
end;
}

1@rgsr,216,136,0	duplicate(#rgsr_warp_7)	#rgsr_warp_8	WARPNPC,1,2
1@rgsr,214,108,0	duplicate(#rgsr_warp_7)	#rgsr_warp_9	WARPNPC,1,2
1@rgsr,216,108,0	duplicate(#rgsr_warp_7)	#rgsr_warp_10	WARPNPC,1,2
1@rgsr,214,76,0	duplicate(#rgsr_warp_7)	#rgsr_warp_11	WARPNPC,1,2
1@rgsr,216,76,0	duplicate(#rgsr_warp_7)	#rgsr_warp_12	WARPNPC,1,2
1@rgsr,214,44,0	duplicate(#rgsr_warp_7)	#rgsr_warp_13	WARPNPC,1,2
1@rgsr,216,44,0	duplicate(#rgsr_warp_7)	#rgsr_warp_14	WARPNPC,1,2

1@rgsr,37,126,0	script	Researcher#rgsr_dum00	4_F_SCIENCE,{
	mes "[ Detained Researcher ]";
	mes "Why do I have to feed this traitors?";
	close;
}

1@rgsr,35,136,7	script	Researcher#rgsr_dum01	4_LGTSCIENCE,{
	mes "[ Detained Researcher ]";
	mes "I want to go home... I just want to go home...";
	close;
}

1@rgsr,38,139,3	script	Researcher#rgsr_dum02	4_M_NFMAN,{
	mes "[ Detained Researcher ]";
	mes "Are you here to save us?";
	mes "Thank you! Thank you!";
	close;
}

1@rgsr,31,186,3	script	Researcher#rgsr_dum03	4_LGTSCIENCE,{
	mes "[ Detained Researcher ]";
	mes "What the hell is happening?";
	mes "Aaaah... I just want to go home...";
	close;
}

1@rgsr,24,186,5	script	Researcher#rgsr_dum04	4_F_SCIENCE,{
	mes "[ Detained Researcher ]";
	mes "Why did you come here to save me?";
	mes "The Enterprise's guards... no wait...";
	next;
	mes "[ Detained Researcher ]";
	mes "I thought that you were the one who kept us in custody...!";
	mes "Why would they do that?";
	close;
}

1@rgsr,25,182,7	script	Researcher#rgsr_dum05	4_M_HUMAN_01,{
	mes "[ Detained Researcher ]";
	mes "These scumbags took my Research Report and I escaped here.";
	mes "It was a spray repellent to block blood-sucking insects!";
	next;
	mes "[ Detained Researcher ]";
	mes "That was my private research, I don't know why they took it!";
	mes "You can't just take away someone else's Research Report.";
	close;
}

1@rgsr,40,186,3	script	Rebellion Crew#rgsr_dum01	4_M_ILYA,{
	mes "[ Rebellion Crew ]";
	mes "I've come prepared, but this was easier than thought.";
	mes "Now I'm stuck here. Hehehehe!";
	close;
}


1@rgsr,33,185,3	script	Rebellion Crew#rgsr_dum02	4_M_REBELLION2,{
	mes "[ Rebellion Crew ]";
	mes "The remaining researchers are gathered here for their security.";
	mes "The Rebellions will protect them and help them escape.";
	close;
}

1@rgsr,31,183,5	script	Rebellion Crew#rgsr_dum03	4_F_ANYA,{
	mes "[ Rebellion Crew ]";
	mes "I thought they had less forces on the inside, but I didn't think they'd have installed toxic gas.";
	mes "Most people have fled already, only the enemies are remaining.";
	close;
}

1@rgsr,195,205,0	script	Research Report#rgsr_00	4_ENERGY_BLUE,{
	mes "It is a data on new efficiency and side effect of new potions.";
	mes "However there is information about the core ingredients.";
	close;
}

1@rgsr,198,199,0	script	Research Report#rgsr_01	4_ENERGY_BLUE,{
	mes "Some of the drawing has been torned.";
	mes "Somebody intentionally destroyed the relevants parts.";
	close;
}

1@rgsr,207,210,0	script	Research Report#rgsr_02	4_ENERGY_BLUE,{
	mes "Parts of the documents were severely damaged.";
	mes "It seems to have been about attempting to create a device using the refraction of light.";
	close;
}
	
1@rgsr,226,226,0	script	Research Report#rgsr_03	4_ENERGY_BLUE,{
	mes "Lloyds's enchantment and processing data.";
	mes "Only the title was left, all the text was removed.";
	close;
}

1@rgsr,231,223,0	script	Research Report#rgsr_04	4_ENERGY_BLUE,{
	mes "The booklet is missing some pages. Someone has deliberately ommited the material.";
	close;
}

1@rgsr,243,223,0	script	Research Report#rgsr_05	4_ENERGY_BLUE,{
	mes "The experimental data has been removed. There are clear traces of someone destroying the information.";
	close;
}