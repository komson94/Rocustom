//===== rAthena Script ===========================================|
//= Episode 17.1 Illusion                                        =|
//===== By: ======================================================|
//= crazyarashi                                                  =|
//===== Current Version: =========================================|
//= 1.0 Initial Version                                          =|
//================================================================|

prt_cas_q,29,28,0	script	#EP171_START	HIDDEN_WARP_NPC,2,3,{
	end;
	
OnTouch:
	if(terra_gloria_main >= 25 && ep_illusion == 0)
		cloaknpc("Nyhill M. Heine#171_prtq",false,getcharid(0));
end;
}

prt_cas_q,21,39,3	script	Nyhill M. Heine#171_prtq	4_EP16_NIHIL,{
	if(!ep_illusion){
		cutin "ep16_nihi_miseria_heine02",2;
		mes "[ Nyhill ]";
		mes "I came here because I wanted to express my gratitude.";
		mes "Thanks to you, things have gotten better...";
		next;
		cutin "ep16_nihi_miseria_heine04",2;
		mes "[ Nyhill ]";
		mes "However, not everything is going as expected.";
		mes "I think I may have to take Peter's place instead.";
		next;
		select("What does that mean?");
		cutin "ep16_nihi_miseria_heine01",2;
		mes "[ Nyhill ]";
		mes "It appears I'm next in line to the throne.";
		mes "This is not what I wanted.";
		next;
		cutin "ep16_nihi_miseria_heine04",2;
		mes "[ Nyhill ]";
		mes "Everyone else has a better right to the throne, they're natural and qualified for it.";
		mes "This is quite strange and unfamiliar to me.";
		next;
		mes "[ Nyhill ]";
		mes "I've been in some discussions with the Schwarz's government, so I'll be busy for a while...";
		next;
		cutin "ep16_nihi_miseria_heine01",2;
		mes "[ Nyhill ]";
		mes "It seems to me they like this arrangement.";
		mes "I believe the relationship between our two countries will be maintained in the future thanks to our efforts.";
		next;
		mes "[ Nyhill ]";
		mes "If you still plan on attacking other enterprise facilities, you may want to rest first.";
		mes "For the time being, you will need strength.";
		next;
		cutin "ep16_nihi_miseria_heine02",2;
		mes "[ Nyhill ]";
		mes "I hope you'll keep on going.";
		mes "Thank you again for all the help.";
		mes "I have to go now.";
		ep_illusion = 1;
		cloaknpc(strnpcinfo(0),true,getcharid(0));
		close3;
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

//= Einbech

einbech,214,80,0	script	#171_EINB_EV	HIDDEN_WARP_NPC,12,12,{
	end;
	
OnTouch:
	if(ep_illusion == 1)
		cloaknpc("Rebellion Crew#171_einb",false,getcharid(0));
end;
}

einbech,219,80,3	script	Rebellion Crew#171_einb	4_M_REBELLION2,{
	if(ep_illusion == 1){
		mes "[ Rebellion Crew ]";
		mes "Wait a second!";
		mes "We have recently widened our base of operations.";
		mes "Due to this expansion, we've been able to set up a new base in Einbroch.";
		next;
		mes "[ Rebellion Crew ]";
		mes "So let me reveal the location to you.";
		mes "It's in a small bar called <NAVI>[Cat on Bullet]<INFO>einbroch,302,329,0,000,0</INFO></NAVI>, not far from the Einbroch railway station...";
		mes "We're preparing for our next operation.";
		next;
		mes "[ Rebellion Crew ]";
		mes "I've delivered you the information, we'll meet again over there!";
		ep_illusion = 2;
		setquest 7850;
		end;
	}
	mes "[ Rebellion Crew ]";
	mes "It's a bar next to the train station of Einbroch.";
	mes "<NAVI>[Cat on Bullet]<INFO>einbroch,302,329,0,000,0</INFO></NAVI>. Don't you think it's a cute name?";
	close;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 1");
end;	
}

rebel_in,68,41,4	script	Rebellion Crew#rebel_in		CLEAR_NPC,{
	switch(ep_illusion){
		case 32:
			mes "[ Rebellion Crew ]";
			mes "Oh! Welcome back!";
			mes "How are you doing lately?";
			next;
			select("We found an entry.");
			mes "[ Rebellion Crew ]";
			mes "I see... There was an entrance...";
			mes "Sorry for the trouble.";
			mes "I'm heading back to Cat on Bullet and I'll be resting a bit.";
			next;
			select("About Dien.");
			mes "[ Rebellion Crew ]";
			mes "Dien is having a cup of tea on the second floor, in her room.";
			ep_illusion = 33;
			completequest 11601;
			setquest 11602;
			end;
			
		case 33:
			mes "[ Rebellion Crew ]";
			mes "Dien is having a cup of tea on the second floor, in her room.";
			end;
			
		default:
			mes "[ Rebellion Crew ]";
			mes "What? I'm busy right now!";
			close;
	}
	
OnInit:
	setunitdata getnpcid(0),UNPC_CLASS,4215;
	setunitdata getnpcid(0),UNPC_SEX,SEX_FEMALE;
	setunitdata getnpcid(0),UNPC_HAIRSTYLE,18;
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 32");
end;
}

rebel_in,161,91,0	script	Ornament Box#rebel_in	HIDDEN_NPC,{
	switch(ep_illusion){
		case 33:
			mes "- It contains an envelope. -";
			next;
			switch(select("Take a look.:Just take it.:Leave it.")){
				case 1:
					cutin "ep171_trio_memory",1;
					mes "- It's an old picture with people you've met before. -";
					close3;
					
				case 2:
					mes "- I took the picture with me, let's give it back to Dien. -";
					ep_illusion = 34;
					completequest 11602;
					setquest 11603;
					getitem 25665,1;
					end;
				
				case 3:
					mes "- Carefully closed the box again. -";
					end;
			}
			end;
			
		case 34:
			mes "- I took the picture with me, let's give it back to Dien. -";
			end;
			
		default:
			mes "- It's locked. -";
			end;
	}
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 33");
end;
}

//= Einbroch
einbroch,42,208,3	script	Lazy#171_einbr	4_M_LAZY,{
	switch(ep_illusion){
		case 17:
			cloaknpc("Kaya#171_einbr",false,getcharid(0));
			cloaknpc("Ashley#171_einbr",false,getcharid(0));
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Here, come. Here it is, Come over here.";
			next;
			select("Where are we going?");
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "That's what I'm trying to define adventurer. How can I set a destination when we have a VIP with us?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Where do we go? The VIP will decide. I will follow wherever you choose.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Don't you have to go the headquarters to investigate?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "I don't have to go to the headquarters to investigates~";
			mes "Let's first look at the situation and the background information we have.";
			mes "Then we'll look at the circumstances surrounding it.";
			next;
			mes "[ Lazy ]";
			mes "Do you know how to investigate, set yourself a concrete goal with a detailed plan? I know a thing or two~";
			next;
			mes "[ Lazy ]";
			mes "Ahahaha! Courtesy, courtesy! Let's be polite to our VIP!";
			npctalk "What Daisy is saying... It's true, but strangely unpleasant.","Kaya#171_einbr",bc_self;
			unittalk getcharid(3),strcharinfo(0) + " : I know right?",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "How about we start with something a little less difficult, how about we start this investigation differently? How about we let the VIP choose.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Well, what am I supposed to choose?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Pick on of the names on the list randomly. If I select one, you'd say I manipulated the results later otherwise.";
			npctalk "I'm the embodiment of disbelief~","",bc_self;
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes ".....";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Why are you looking at me like that? Don't you believe my heart?";
			npctalk "Do you like my heart? I'm afraid I cant. My heart already has a owner.","",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Here, I choose that one. What are we going to do next?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Let me see... ^0000FFPatrick Kaufman^000000.";
			mes "Well... that name is long, let's call him ^0000FFPat^000000 instead.";
			next;
			select("Don't change his name!");
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Oh? Is it not economical? What's wrong, we'll save time using the name.";
			mes "Also this will be a codename we can use among ourselves when refer to this scientist.";
			next;
			mes "[ Lazy ]";
			mes "I've been an agent for a long time, I know these things. There's an official way to handle these, but I can't tell you that information.";
			unittalk getcharid(3),strcharinfo(0) + " : I'm not surprised anymore.",bc_self;
			npctalk "Oh... It's possible.","Kaya#171_einbr",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Now, can we all go together and find Pat? Lighthalzen is to the east. It is often said to be a ^0000FFslum^000000. Of course, our VIP knows all about this already, right?";
			mes "You'd have read this in your paperwork.";
			npctalk "As you can see, no misunderstanding, only the truth~","",bc_self;
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "What's your plan?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Since he was a child, he would pick things up and fix them, and then resell. It's a talent that's been lost nowadays.";
			next;
			mes "[ Lazy ]";
			mes "At the age 21, he received a special award for low-income families. It caused a lot of envy from the people around him.";
			npctalk "Family pride~ huh, isn't that great.","",bc_self;
			next;
			mes "[ Lazy ]";
			mes "He was moved to another Rekenber facility after 5 months, and then there is no record after that.";
			mes "That's all the information about Pat.";
			npctalk "This is as far as I've investigated.","",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Our VIP has chosen a very suitable candidate for our investigation. I applaud you. It was a good idea.";
			mes "It's not a common person on the list.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Are we only going to investigate him? What about the others?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "How do you want to investigate so many people with only so few of us?";
			mes "We focus on one person, don't you know how it works?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "After all, they all disappeared in a similar fashion. So once we figure out what happened to one of them, we'll know what happened to the rest too.";
			next;
			select("What am I going to do here?");
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Good morning~ From now on VIP's, the journey of Pat from his work to Rekenber to the present is for us to figure out~ with Lazy and his team~";
			npctalk "Woah~ I usually get applauded here.","",bc_self;
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "So what? When you do your investigations, do you think it's a game?";
			npctalk "Vice President, it's not too late to go back now.","Ashley#171_einbr",bc_self;
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Do I seem like a joke to you VIP?";
			mes "I'm quite serious, don't you believe me VIP?";
			next;
			mes "[ Lazy ]";
			mes "We'll follow Pat's work schedule. We can follow his traces and understand a bit more about what happened as to why he's missing.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "You've never taken a good look at the Lighthalzen village. I'm from a big city and I know a few places I can recommend to start with.";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "When you say Lighthalzen is a village, what do you mean?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Guard, are you tired? Compared to Yuno, Lighthalzen is a small village.";
			mes "Yuno is a really nice place. I often say this. Yuno is the city of Sages. Well, I would say it differently.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "The jewel of Rune-Midgard, the heart of the country, is Yuno. Everyone should visit at least once.";
			mes "If anyone would ask me about the future of Rune-Midgard, I'd bet my life it would be the brilliant city of Yuno.";
			unittalk getcharid(3),strcharinfo(0) + " : Lazy, I need you to be more modest.",bc_self;
			npctalk "Aaaah. I love Yuno. *Laughs*","",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Anyway, there's nothing as good as traveling around here and there.";
			mes "It's also very good to deceive others. Why would suspect a tourist? Right?";
			npctalk "The VIP will take his special itinerary, we'll be waiting for you there.","",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Should we really do that? Go to the headquarters and investigate?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "There are some things you can't learn from paperwork. Can a VIP explain what the yellow color is someone who doesn't know yellow?";
			next;
			mes "[ Lazy ]";
			mes "Wouldn't it be quicker to just show the person yellow flowers and explain it?";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "There are many things I don't know outside my papers. That's partly why I came along with you.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "That's right. Do you feel bad? It's the truth though. Only mouth to mouth reveal true facts.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I understand. If we don't go over there, there will be only controversy with our reports.";
			npctalk "Vice President? Are you serious?","Ashley#171_einbr",bc_self;
			npctalk "Doesn't it make sense to you? If I don't understand something, I have to see it.","",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "That's the purpose of this tour. Now let's go, we don't have much time.";
			mes "Let's head over there with a non-fair First Class seat, it will be more comfortable.";
			next;
			select("First Class? Last time we traveled...");
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Hey!! I'm on official duty now! I'm also going to take First Class.";
			mes "Does the adventurer not have a First Class fake pass?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Nobody has the money to pay First Class except the VIP. He can just bring us along.";
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "Hmm!";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Thank you! Courtesy, courtesy! Now, let's all go to <NAVI>[Lighthalzen]<INFO>lighthalzen,259,215,0,101,0</INFO></NAVI>?";
			ep_illusion = 18;
			completequest 17003;
			setquest 17004;
			close2;
			cutin "",255;
			warp "lighthalzen",246,76;
			end;
			
		case 18:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Now, let's all go to <NAVI>[Lighthalzen]<INFO>lighthalzen,259,215,0,101,0</INFO></NAVI>.";
			close2;
			cutin "",255;
			warp "lighthalzen",246,76;
			end;
			
		case 19:
		case 20:
		case 21:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Aren't you supposed to be working right now?";
			close3;
						
		default:
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Hourray, finally some air, huh.";
			mes "Let's go to Yuno. Huh.";
			close3;

	}
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 17");
end;
}

einbroch,41,204,7	script	Kaya#171_einbr	4_EP17_KAYA,{
	cutin "ep171_kaya01",2;
	mes "[ Kaya ]";
	mes "Don't you want to hear what Daisy want to say?";
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

einbroch,39,205,7	script	Ashley#171_einbr	4_EP17_AS,{
	cutin "ep171_as02",2;
	mes "[ Ashley ]";
	mes "Do you know what Daisy is trying to drag us into? Can you believe this?";
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

//= Einbroch Field
ein_fild01,95,146,0	script	#171_EV_EINF01	HIDDEN_WARP_NPC,15,15,{
	end;
	
OnTouch:
	if(ep_illusion == 27)
		cloaknpc("Kaya#einf",false,getcharid(0));
end;
}

ein_fild01,95,146,5	script	Kaya#einf	4_EP17_KAYA,{
	switch(ep_illusion){
		case 27:
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Here we are, Sector 01 - Section 95-146 in the Einbroch Mountains.";
			mes "This is the new laboratory.";
			next;
			select("There's nothing here.");
			cutin "ep171_kaya02",0;
			mes "[ Kaya ]";
			mes "I thought it was here. Lazy must be wondering ^0000FFwhat this means.^000000 I only saw the world from sitting at my desk. I believed my view was true.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Everything I've heard and saw... I feel as if there was an invisible person manipulating everything. This is not a scenario I thought could be possible.";
			next;
			cutin "ep171_kaya02",0;
			mes "[ Kaya ]";
			mes "Even if everything looks fine on the surface, there are so many lies within. I've been deceived.";
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "If you don't investigate with suspicious, you won't see any problems on the surface.";
			next;
			cloaknpc("Ashley#einf",false,getcharid(0));
			cloaknpc("Lazy#einf",false,getcharid(0));
			mes "[ Ashley ]";
			mes "But that's so... not trusting...";
			npctalk "But that's so... not trusting...","Ashley#einf",bc_self;
			npctalk "But it's very useful, isn't it?","Lazy#einf",bc_self;
			next;
			mes "[ Ashley ]";
			mes "Yes... that's true.";
			npctalk "Yes... that's true.","Ashley#einf",bc_self;
			npctalk "If you want, I can teach you more tricks. It's very useful in the real world.","Lazy#einf",bc_self;
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Hey, you're there alrready. How is it? What have you found out with your own two eyes?";
			npctalk "Oh... are there more techniques? I'm glad to hear it.","Ashley#einf",bc_self;
			next;
			cutin "ep171_kaya02",0;
			mes "[ Kaya ]";
			mes "I realized that papers are easy tools to deceive someone who's only sitting at a desk and doing their own thing.";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "There is no lab here. There was nothing on our end either.";
			mes "Absolutely nothing.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "If everything on that document is false, then we can't find any more information.";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "What do we do now?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Well. We have to keep looking for the location of this new laboratory. When we find it, we'll have to research it from the inside.";
			npctalk "Who else has better ideas?","Lazy#einf",bc_self;
			next;
			select("You don't have anything else Lazy?");
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Dear adventurer, have you forgotten who's been helping you now? The Rebellion has been roaming these areas.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "The laboratory that I discovered a while, and the waste site. I'm sure it's only a matter of time before it's revealed. It must be nearby.";
			next;
			select("How do you know?");
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "It requires a large workforce and a lot of materials to build a research facility. Even after its construction, materials should still be constantly coming in.";
			mes "Wouldn't it be too hard for such supplies to pass through the borders?";
			next;
			mes "[ Kaya ]";
			mes "So the laboratory is probasbly still in Schartzwald. The materials can't be transported in the open,";
			mes "so we have to look for a secret location, I guess it's going to be in one of those locations.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Did you hear that? That's smart.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "As of now, Rekenber will now ^0000FFdedicate itself to cooperate with the investigation.^000000 Please tell me everything you need. We'll support you anyway we can.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Alright, I'm glad to hear it, and I will gladly accept your cooperation.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I would like to personally apologize to Daisy. I'm sorry I didn't believe you. Thank you for coming to us.";
			next;
			mes "[ Kaya ]";
			mes "Daisy, if you need anything, please come and visit me at anytime.";
			mes "You'll always be welcome.";
			npctalk "Hmm... I don't have any objection with that.","Lazy#einf",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "In the future, please call me Lazy. Let's go with me for another adventurer one day. Come to Yuno everynow and then.";
			npctalk "I always hide in Yuno's restaurants~","Lazy#einf",bc_self;
			next;
			mes "[ Lazy ]";
			mes "But that's for another day. Let's focus on the mission at hand.";
			next;
			select("Should I investigate further?");
			mes "[ Lazy ]";
			mes "Why not? What more can you do here, Hmm. I'm a little hungry. My legs hurt too. I need to get back to work. I'll have to deal with the VIP as well.";
			next;
			mes "[ Lazy ]";
			mes "As such, I'm going to report the investigation regarding Pat's journey.";
			mes "Everyone, let's go back to <NAVI>[Cat on Bullet]<INFO>pub_cat,93,105,0,000,0</INFO></NAVI>~";
			getexp 600000,600000;
			ep_illusion = 28;
			completequest 17013;
			setquest 17014;
			getitem 25723,20;
			close3;

		case 28:
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Did you go to <NAVI>[Cat on Bullet]<INFO>pub_cat,93,105,0,000,0</INFO></NAVI> yet?";
			mes "Let's hurry. There's still a lot to do.";
			close3;
	}
	end;
		
OnInit:
	cloaknpc(strnpcinfo(0),true);
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 27");
end;
}

ein_fild01,94,145,5	script	Ashley#einf	4_EP17_AS,{
	cutin "ep171_as03",2;
	mes "[ Ashley ]";
	mes "Let's go back to <NAVI>[Cat on Bullet]<INFO>pub_cat,93,105,0,000,0</INFO></NAVI>.";
	mes "I think we should hurry.";
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

ein_fild01,97,144,1	script	Lazy#einf	4_M_LAZY,{
	cutin "16lei_03",2;
	mes "[ Lazy ]";
	mes "Let's go to <NAVI>[Cat on Bullet]<INFO>pub_cat,93,105,0,000,0</INFO></NAVI>.";
	mes "I'm already hungry.";
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

ein_fild03,347,219,0	script	#171_mem_ev_1	HIDDEN_WARP_NPC,1,1,{
	end;
	
OnTouch:
	.@npc = atoi(replacestr(strnpcinfo(2),"171_mem_ev_",""));
	switch(.@npc){
		case 1: .@quest_id = 11596; break;
		case 2: .@quest_id = 11597; break;
		case 3: .@quest_id = 11598; break;
	}
	if(ep_illusion == 30 && isbegin_quest(.@quest_id) == 1){
		switch(.@npc){
			case 1:
			case 2:
				mes "- Nothing  special here. -";
				mes "- Let's look elsewhere. -";
				break;
				
			case 3:
				mes "- There doesn't seem to be anything. -";
				mes "- Let's go back to the Rebellion Crew. -";
				break;
		}
		completequest .@quest_id;
		setquest (.@quest_id + 1);
		questinfo_refresh();
	}
end;

OnInit:
	.@npc = atoi(replacestr(strnpcinfo(2),"171_mem_ev_",""));
	switch(.@npc){
		case 1: .@quest_id = 11596; break;
		case 2: .@quest_id = 11597; break;
		case 3: .@quest_id = 11598; break;
	}
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 30 && isbegin_quest(" + .@quest_id + ") == 1");
end;
}

ein_fild03,268,207,0	duplicate(#171_mem_ev_1)	#171_mem_ev_2	HIDDEN_WARP_NPC,1,1
ein_fild03,218,266,0	duplicate(#171_mem_ev_1)	#171_mem_ev_3	HIDDEN_WARP_NPC,1,1

//= Pub Cat

pub_cat,93,105,4	script	Philofontes#171_cat	4_M_PHILOFONTES,{
	if(ep_illusion < 2){
		mes "[ Tess ]";
		mes "I never knew there was such a place.";
		mes "It's more amazing than you think.";
		close;
	}
	switch(ep_illusion){
		case 2:
			cutin "ep16_tes01",1;
			npctalk "That's it.","",bc_self;
			mes "[ Tess ]";
			mes "I've been waiting for you.";
			mes "This place is a bit chaotic, but the Rebellions rather like it here.";
			next;
			mes "[ Tess ]";
			mes "This place will be used as a base while you carry out your other duties.";
			next;
			mes "[ Tess ]";
			mes "Anyhow, I've analyzed all the information gathered from the last operation.";
			mes "It turns out there are more facilities with secret laboratories.";
			next;
			mes "[ Tess ]";
			mes "We already expected as much when we started our research.";
			mes "It's not just speculation this time, the evidence is clear now.";
			next;
			mes "[ Tess ]";
			mes "Elena Bolkova is organizing an advance team for investigating the suspected areas.";
			mes "I think it would greatly help if you joined her team too..";
			next;
			cloaknpc("Elena Bolkova#171_cat",false,getcharid(0));
			cutin "162elena_02",2;
			mes "[ Elena Bolkova ]";
			mes "Hey~ Tess!";
			mes "We sent a recon team to investigate the areas you spoke about.";
			next;
			select("Where is it?");
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "Oh you're the adventurer? Did Tess call you?";
			mes "It really help if someone as strong as you joined us.";
			next;
			mes "[ Elena Bolkova ]";
			mes "Are you really sure about this place?";
			mes "Lucky said it's just an abandoned smelting plant after a mine close.";
			next;
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "I know it doesn't look like much,";
			mes "but thanks to the previous data collected by the Werner Institute...";
			mes "We found an entry to the ^0000FFabandoned waste of Rudus^000000.";
			next;
			mes "[ Tess ]";
			mes "We figured out a path or a location to get inside, so I'd like you to investigate it further.";
			next;
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "Anyway, so this area with all the experiments?";
			mes "Then I'll go to the field.";
			mes "The adventurer should come after me.";
			next;
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "Then I'll inform the adventurer of your location separately.";
			next;
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "I'm going alone now.";
			next;
			cloaknpc("Elena Bolkova#171_cat",true,getcharid(0));
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "Why not join us and see the situation for yourself?";
			mes "The location is Einbroch North-East field. The code name for the operating system is Rudus.";
			next;
			ep_illusion = 3;
			completequest 7850;
			setquest 7851;
			mes "[ Tess ]";
			mes "I'll call this location <NAVI>[Rudus]<INFO>ein_fild05,158,284,0,101,0</INFO></NAVI> from now on.";
			mes "I would be grateful if you joined.";
			next;
			mes "[ Tess ]";
			mes "In the meantime, I will try and learn more about Lighthalzen.";
			mes "You should received enough information to start investigating now.";
			close3;

		case 3:
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "<NAVI>[Rudus]<INFO>ein_fild05,158,284,0,000,0</INFO></NAVI> is at Einbroch North-East field.";
			mes "If you join, it will definitely help.";
			close3;
			
		case 7:
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "You went there?";
			mes "Hmm, so you've found in the barrier in the closed mine, and there are monsters behind it?";
			next;
			mes "[ Tess ]";
			mes "I don't think it's a research facility, even by looking at the other member's report.";
			mes "It seems to be a place to cover up unsuccesful experiments.";
			next;
			cutin "ep16_tes03",1;
			mes "[ Tess ]";
			mes "For some reason, there's been no accident on the outside. Tsk.";
			mes "For the time being, I think I'm going to split from the rebellions.";
			next;
			mes "[ Tess ]";
			mes "Unfortunately, Rudus didn't bring out great results. Bolkova has been quite helpful.";
			next;
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "I'll have to go to the backdoor now room now.";
			mes "It seems I've picked up bad customers, but with the adventurer's help it shouldn't be a problem.";
			ep_illusion = 8;
			completequest 7859;
			setquest 7860;
			questinfo_refresh();
			close3;

		case 8:
		case 9:
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "It's that room over there. It's a place where only rebellions can go in or out.";
			mes "All the captains are inside.";
			close3;

		case 10:
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "It's the building at the top left of our Headquarters, in <NAVI>[Lighthalzen]<INFO>lighthalzen,56,270,0,000,0</INFO></NAVI>.";
			mes "There will be Rekenber guards sent by Ashley and troop dispatched by the republic.";
			next;
			mes "[ Tess ]";
			mes "Erst will also be there, you'll find the location easily.";
			mes "I hope this mission goes well.";
			close3;

		case 11:
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "I heard the story.";
			mes "You joined an operation with Erst and Ashley to take back the laboratory.";
			next;
			mes "[ Tess ]";
			mes "Please bring back as much data and information as you can from there.";
			mes "If not now, when would you shake up the Enterprise's labs?";
			close3;
			
		case 12:
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "You're back.";
			mes "Erst came back first and I wasn't sure something had happened to you.";
			next;
			mes "[ Tess ]";
			mes "The information I got from Erst was incredible.";
			mes "And it seems Lazy has something to tell you.";
			next;
			mes "[ Tess ]";
			mes "Kaya should be there too.";
			mes "I have to analyze the data everyone is giving me, it's piling up.";
			mes "You have enough to do already.";
			ep_illusion = 13;
			completequest 7862;
			setquest 7864;
			getitem 25669,25;
			getexp 1000000,800000;
			close3;
			
		case 13:
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "Lazy seems to be up to something.";
			mes "He's somewhere here in the pub, go and find him.";
			close3;
			
		case 28:
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "I thought you were investigating with Lazy, it looks like you didn't get great results.";
			next;
			mes "[ Tess ]";
			mes "I finished analyzing the information you gathered from Regenschirm earlier, there were traces of supplies and research data.";
			next;
			mes "[ Tess ]";
			mes "So far, I believe it was a trick from the Enterprise, from those who sit back at the company.";
			mes "Huh...";
			cloaknpc("Kaya#171_cat3",false,getcharid(0));
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I agree with your assessment.";
			mes "The more I learn about the truth, the less I understand what's going on.";
			npctalk "Oh, what happened?","",bc_self;
			next;
			mes "[ Kaya ]";
			mes "What I've seen so far was only the tip of the iceberg.";
			mes "My eyes are now wide opened.";
			npctalk "I'm sorry to interupt so suddenly.","Kaya#pub_cat_dummy",bc_self;
			next;
			cutin "ep16_tes02",1;
			mes "[ Tess ]";
			mes "It seems it was from the group that pretended to be part of the security personnel and then attacked the laboratory.";
			mes "What could their motives be?";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Tsk, I think I know who's behind all of this.";
			mes "There have only been a few people who have ran unreasonable experiments at the laboratory.";
			next;
			mes "[ Kaya ]";
			mes "We had fired them because of their unethical experiments, I'm guessing it's them.";
			next;
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "Hmm... That part of the investigation still needs more clarity.";
			mes "I'm going to try and find more information about the new laboratories.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I will leave this part to you.";
			mes "I'm going back to my laboratory and do some research.";
			next;
			mes "[ Kaya ]";
			mes "Please excuse me.";
			next;
			cloaknpc("Kaya#171_cat3",true,getcharid(0));
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "... then I'll keep you informed about the next operation.";
			next;
			mes "[ Tess ]";
			mes "There is another closed mine at Einbroch, in the North-West region.";
			mes "There are many abandoned mines in the area...";
			next;
			cutin "ep16_tes03",1;
			mes "[ Tess ]";
			mes "I should have looked at them more, but I don't have enough resources...";
			next;
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "Anyway, this time around, the elders of the Rebellion are going to participate in the operation.";
			mes "They are very strong supporters.";
			next;
			mes "[ Tess ]";
			mes "Meet with a <NAVI>[Rebellion Crew]<INFO>ein_fild03,278,269,0,000,0</INFO></NAVI> member at the North-West region of Einbroch.";
			ep_illusion = 29;
			completequest 17014;
			setquest 7865;
			close3;
			
		case 29:
			mes "[ Tess ]";
			mes "Meet with a <NAVI>[Rebellion Crew]<INFO>ein_fild03,278,269,0,000,0</INFO></NAVI> member at the North-West region of Einbroch.";
			end;
			
		default:
			if(isbegin_quest(7863) == 1){
				cutin "ep16_tes01",2;
				mes "[ Tess ]";
				mes "Is it related to  the laboratory's security.";
				mes  "Ashley told me you had something to deliver.";
				next;
				mes "[ Tess ]";
				mes "I think it's a concious decision from Schlein to have left these documents.";
				mes "Tsk, that Schlein.";
				next;
				mes "[ Tess ]";
				mes "I understand.";
				mes "I will analyze this along with the other materials.";
				getexp 200000,200000;
				completequest 7863;
				close3;
			}
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "I'm a bit tired. There are tons of documents to analyze.";
			close3;			
	}
	
OnInit:
	setarray .v,2,7,12,28;
	for(.@i = 0; .@i < getarraysize(.v); .@i++)
		questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == " + .v[.@i]);
end;
}


pub_cat,95,103,3	duplicate(dummynpc)	Elena Bolkova#171_cat	4_F_ELENA

pub_cat,151,105,0	script	#EP171_EVT_CAT00	HIDDEN_WARP_NPC,3,2,{
	end;
	
OnTouch:
	switch(ep_illusion){
		case 8:
			cloaknpc("Philofontes#171_cat2",false,getcharid(0));
			cloaknpc("Middle-Aged Man#171_cat",false,getcharid(0));
			cloaknpc("Rekenber Senior Guard#171_cat",false,getcharid(0));
			cloaknpc("Commander Erst#171_cat",false,getcharid(0));
			sleep2 500;
			npctalk "I will cooperate this one time only, okay?","Commander Erst#171_cat",bc_self;
			break;
			
		case 9:
			cloaknpc("Philofontes#171_cat2",false,getcharid(0));
			cloaknpc("Middle-Aged Man#171_cat",false,getcharid(0));
			break;
			
		case 10:
			cloaknpc("Middle-Aged Man#171_cat",false,getcharid(0));
			break;
			
		default:
			break;
	}
end;
}

pub_cat,105,66,0	script	#EP171_EVT_CAT01	HIDDEN_WARP_NPC,12,5,{
	end;
	
OnTouch:
	if(ep_illusion == 13){
		cloaknpc("Lazy#171_cat",false,getcharid(0));
		cloaknpc("Kaya#171_cat",false,getcharid(0));
		cloaknpc("Ashley#171_cat",false,getcharid(0));
		end;
	}
	if(ep_illusion < 17){
		cloaknpc("Lazy#171_cat2",false,getcharid(0));
		cloaknpc("Kaya#171_cat",false,getcharid(0));
		cloaknpc("Ashley#171_cat",false,getcharid(0));
		end;
	}
	if(ep_illusion == 17)
		cloaknpc("Lazy#171_cat2",false,getcharid(0));
end;
}

pub_cat,160,102,5	script	Philofontes#171_cat2	4_M_PHILOFONTES,{
	switch(ep_illusion){
		case 8:
			cutin "ep162_est01",2;
			mes "[ Erst ]";
			mes "It's your operation. Do you have no support available?";
			mes "How the hell you become a government without an army?";
			next;
			cutin "ep16_tes01",0;
			mes "[ Tess ]";
			mes "I can't say anything about that.";
			mes "I don't have the authority to create and grow my own army.";
			next;
			cutin "ep162_est03",2;
			mes "[ Erst ]";
			mes "I know. I can't ask that to a general soldier.";
			mes "You don't have the power to change that.";
			next;
			select("Why are you all here?!");
			cutin "ep162_est02",2;
			mes "[ Erst ]";
			mes "Right? Isn't it weird for you too?";
			mes "It's really strange for us as well, are you aware of what's going on adventurer?";
			next;
			cutin "ep162_est03",2;
			mes "[ Erst ]";
			mes "It's impressive how they've managed to make this meeting inside the pub will all of us, and now a Rebellion unit is helping out the Enterprise.";
			next;
			cutin "ep162_est02",2;
			mes "[ Erst ]";
			mes "Isn't it truly wonderful and amazing? I've seen many things, but I never thought that this day would come.";
			mes "But why are you here?";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Middle-Aged Man ]";
			mes "Sigh.. I don't know why we're so hostile with each other.";
			mes "Still, there are only few organizations that contribute to the people...";
			next;
			cutin "ep162_est02",2;
			mes "[ Erst ]";
			mes "Do you really believe so?";
			mes "Don't you know why we're called the Rebellion in the first place?";
			mes "You're only thinking about what you want.";
			next;
			cutin "ep162_est01",2;
			mes "[ Erst ]";
			mes "Yeah. That's a corporation. How many companies do you have now?";
			mes "Your president always look down on us.";
			next;
			cutin "ep16_tes03",0;
			mes "[ Tess ]";
			mes "That's not it, Erst.";
			mes "You do know there's a reason for that, right?";
			next;
			cutin "ep162_est03",2;
			mes "[ Erst ]";
			mes "I've already decided to send a support unit.";
			mes "Even so, is that really going to be enough?";
			npctalk ".....","Middle-Aged Man#171_cat",bc_self;
			npctalk "....hick...","Rekenber Senior Guard#171_cat",bc_self;
			next;
			select("So what's going on?");
			mes "[ Erst ]";
			mes "I'm a little too excited. I'll shut up. Tess, explain it please.";
			next;
			cutin "ep16_tes01",0;
			mes "[ Tess ]";			
			mes "To put it simply, our affiliated Enterprise research institute, Regenschirm, is occupied by a large group of enemies.";
			mes "A special unit under Erst's command will be dispatched for the recapture.";
			next;
			mes "[ Tess ]";	
			mes "So that's why Erst was so nervous.";
			next;
			select("Why aren't the Enterprise guards helping?");
			mes "[ Tess ]";	
			mes "Well you see...";
			npctalk "That's all my fault!","Rekenber Senior Guard#171_cat",bc_self;
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "It all started because of the traitor within the guards.";
			mes "Oh, sorry, I'm senior Rekenber security officer, Ashley.";
			next;
			mes "[ Ashley ]";
			mes "The traitor is the chief security officer, Schlein, who has substancial support within the guard forces.";
			next;
			mes "[ Ashley ]";
			mes "It's these guards, let by Schlein,";
			mes "Who currently occupies the Regenschirm.";
			mes "Most of the armed forced join with Schlein, and they started calling themselves Heart Hunters.";
			next;
			cutin "ep171_as02",1;
			mes "[ Ashley ]";
			mes "Yes. It was the Heart Hunters.";
			mes "On the day of the incident, at midnight, the guards changed uniform for something unusual.";
			unittalk getcharid(3),strcharinfo(0)+ " : Heart Hunter?!",bc_self;
			next;
			mes "[ Ashley ]";
			mes "In the daytime, our team is in charge of patrols and security. At nighttime, the security guards of Schlein take over.";
			next;
			mes "[ Ashley ]";
			mes "The shifts scheduled for that day came in wearing new uniforms, it was a mistake for me to believe it was an experimental outfit.";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "They seized the daytime crew in an instant.";
			mes "With their deception, they took all over the security guards simultaneously.";
			next;
			mes "[ Ashley ]";
			mes "I tried to send an emergency request to get a response team, but they are extraordinarily strong...";
			mes "Only more guards ended up being sacrificed and we didn't have any success.";
			next;
			cutin "ep171_as02",1;
			mes "[ Ashley ]";
			mes "And the one responsible for this was Schlein, showing up in a new uniform.";
			mes "He asked me if I wanted to become stronger. If I accepted his offer, I would become a Heart Hunter too.";
			next;
			mes "[ Ashley ]";
			mes "I refused and left, only to watch more guards suffering.";
			mes "Most of my crew suffered huge casualties, as I just stood by in shame...";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "The guards wearing the new uniform, who followed Schlein, may not have all been Heart Hunters.";
			mes "Schlein only gathers the strongest people after all.";
			next;
			select("I've met Heart Hunters too...");
			cutin "ep162_est01",2;
			mes "[ Erst ]";
			mes "Did you see any more Heart Hunters?";
			mes "Weren't those guards we fought in the battlefield some time ago?";
			next;
			mes "[ Erst ]";
			mes "If our opponents are Heart Hunters, that's interesting.";
			mes "I should be able to handle them quickly.";
			mes "I'll go first.";
			next;
			mes "[ Erst ]";
			mes "There, what do you say Ashley?";
			next;
			cutin "ep171_as02",1;
			mes "[ Ashley ]";
			mes "Yes? Yes! How can I help you with that?";
			next;
			cutin "ep162_est02",2;
			mes "[ Erst ]";
			mes "Couldn't you just have said that?";
			mes "Are you afraid of these guards?";
			mes "Don't you think we should go now, after you tell us the way?";
			mes "Come on? Like the first operation we did.";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "Yes. I see. You're right.";
			mes "I should go and explain the situation in more details...";
			npctalk "So Vice President....","Rekenber Senior Guard#171_cat",bc_self;
			next;
			cutin "ep171_kaya02",0;
			mes "[ Middle-Aged Man ]";
			mes "Don't worry about me.";
			mes "Is it safe for me to stay here?";
			mes "I have something I must do. You do what you have to do on your end.";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "Roger. Then I will discuss strategies with Erst.";
			next;
			cutin "ep162_est03",2;
			mes "[ Erst ]";
			mes "Tess, watch out your back. Haha, you'll be alright.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Middle-Aged Man ]";
			mes "It all went so fast.";
			mes "I wish we could talk more in-depth about this operation.";
			ep_illusion = 9;
			cloaknpc("Rekenber Senior Guard#171_cat",true,getcharid(0));
			cloaknpc("Commander Erst#171_cat",true,getcharid(0));
			close3;
	
		case 9:
			npctalk "I think Kaya has something else to say.","",bc_self;
			end;
	}

OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 8");
	cloaknpc(strnpcinfo(0),true);
end;
}

pub_cat,163,102,3	script	Middle-Aged Man#171_cat	4_EP17_KAYA,{
	switch(ep_illusion){
		case 8:
			cutin "ep171_kaya01",0;
			mes "[ Middle-Aged Man ]";
			mes "I don't think I should be starting this conversation, so why do not you speak with Tess instead?";
			close3;
			
		case 9:
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Now I can formally introduce myself.";
			mes "My name is Kaya. I work with the Rekenber Division.";
			next;
			mes "[ Kaya ]";
			mes "There aren't a lot of security personal remaining in the Enterprise, because most of them betrayed Rekenber.";
			next;
			mes "[ Kaya ]";
			mes "So now, the rest of us are doing our best to shutdown Regenschirm...";
			mes "I've sent help requests here and there, but I haven't gotten a good replies yet.";
			next;
			cutin "ep16_tes01",1;
			mes "[ Tess ]";	
			mes "An unusually large number of companies have contacted the Rekenber directly for support.";
			next;
			mes "[ Tess ]";
			mes  "But as a general soldier in the Schwartz Republic, it was too difficult to handle it ourselves and eventually we took advantage of the Rebellion and the adventurer's strength.";
			next;
			cutin "ep171_kaya02",2;
			mes "[ Kaya ]";
			mes "I can understand why Erst was so angry.";
			mes "There are many people who are blind to the corrupt management and others who work on their own accord.";
			next;
			mes "[ Kaya ]";
			mes "I've came here to purge the evil from the Enterprise.";
			mes "However, I hadn't realize these rotten people were so deeply connected in politics.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "The citizen's safety is threatened,";
			mes "they don't know what the enterprise is thinking. Neither can they officially seek and request help.";
			next;
			cutin "ep16_tes03",1;
			mes "[ Tess ]";
			mes "Sigh, wait.";
			mes "You're not wrong, of course, but there are separate reasons for this.";
			mes "It look like your sister has made some kind of deal with the president.";
			next;
			cutin "ep171_kaya03",2;
			mes "[ Kaya ]";
			mes "No, it wouldn't have been necessary to make such a deal if the right people were governing in the first place!";
			next;
			cutin "ep16_tes03",1;
			mes "[ Tess ]";
			mes "Don't you think if the Enterprise had managed its properly to begin with, we wouldn't be in this situation right now?";
			next;
			cutin "ep171_kaya02",2;
			mes "[ Kaya ]";
			mes ".....";
			mes "I'm sorry, I got worked up.";
			mes "With our plan in action, I believe we have a better future ahead of us.";
			next;
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "I agree, we have to act quickly though.";
			mes "So " + strcharinfo(0) + ",";
			mes "If possible, could you join Erst and do some planning?";
			next;
			mes "[ Tess ]";
			mes "Ashley said they were called 'Heart Hunters'.";
			mes "Maybe there is a connection with the previous incident. There maybe additional information we can send to Rune-Midgard.";
			next;
			mes "[ Tess ]";
			mes "Kaya and I will stay here to process and relay the incoming information.";
			mes "I will leave the battle side of things to you and Erst.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Please take care.";
			completequest 7860;
			setquest 7861;
			ep_illusion = 10;
			next;
			cutin "ep16_tes01",1;
			mes "[ Tess ]";
			mes "I'll see you outside.";
			close2;
			cutin "",255;
			questinfo_refresh();
			cloaknpc("Philofontes#171_cat2",true,getcharid(0));
			end;
			
		case 10:
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I'm sorry I can't help you anymore.";
			mes "I think it may turn into a messy fight.";
			close3;
	}
	end;
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 9");
	cloaknpc(strnpcinfo(0),true);
end;
}


pub_cat,165,103,3	script	Rekenber Senior Guard#171_cat	4_EP17_AS,{
	cutin "ep171_as02",1;
	mes "[ Ashley ]";
	mes "Oh, hello there! My name is Ashley,";
	mes "from the Rekenber secury support team!";
	mes "I came here with Kaya!";
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

pub_cat,166,100,3	script	Commander Erst#171_cat	4_F_ESTLOVELOY,{
	cutin "ep162_est03",2;
	mes "[ Erst ]";
	mes "Why should we help them?";
	mes "Can you explain why we have to cooperate with them?";
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

pub_cat,106,69,7	script	Lazy#171_cat	4_M_LAZY,{
	if(ep_illusion == 13){
		cutin "16lei_03",0;
		mes "[ Lazy ]";
		mes "Look, that's all nice and good to have ^0000FFfacts^000000, but you can't use them as firepower.";
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "I've said it a few times already.";
		mes "This is it, those are all the ^0000FFfacts.^000000";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "Truth be told, it doesn't sound convincing. If I look at the front page of your report, it does not at all align with my investigation results.";
		npctalk "If what you've written is true, then it's also true that the sky is red.","",bc_self;
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "If that's the case, then we should review the investigation methods and the credibility of the source.";
		next;
		cutin "16lei_03",0;
		mes "[ Lazy ]";
		mes "Oh sure, I have a lunch menu survey from the people in the neighborhood... is that what you want to use as facts?";
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";		
		mes "That's not what I said at all...";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "What, you don't believe me? Yeah? Is that it? You don't think it's a reliable source of information?";
		next;
		cutin "ep171_kaya03",2;
		mes "[ Kaya ]";
		mes "Isn't it common sense that ^0000FFpeople inside the Enterprise know more?^000000";
		mes "Not only would we have access to more data, but the quality would be much higher than what's available to an outsider.";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "Don't you think the Vice President would only share with us ^0000FFwhat he want us to know?^000000";
		mes "Am I supposed to suspend all critical thinking and unquestioningly believe you?";
		next;
		mes "[ Lazy ]";
		mes "Won't that mean you can just report to the President and hide a plan from us? Yeah? Right?";
		npctalk "No big crowds right?","",bc_self;
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "I never said that.";
		next;
		select("Lazy, what's wrong?");
		cutin "16lei_01",0;
		mes "[ Lazy ]";
		mes "Adventurer? Adventurer!! Hey, I haven't died yet!! Never been better!!";
		mes "Listen to me.";
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "Lazy? Is you name Lazy? Didn't you introduce yourself as Daisy?";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "Oh, that? Don't worry about it, it's the name I use to distract people. There, now you know me. Oh by the way... nevermind, you don't need to know that.";
		next;
		select("If it's Daisy... are you a flower?");
		mes "[ Lazy ]";
		mes "Look, although it may be true in my case, it doesn't mean it applies to me.";
		mes "Don't take it too personal. Who in the world only has one name?";
		unittalk getcharid(3),strcharinfo(0)+ " : Everyone else has one name?",bc_self;
		npctalk "Really?!","",bc_self;
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "If you don't have anything else to say, then please explain why your name is different.";
		next;
		cutin "16lei_03",0;
		mes "[ Lazy ]";
		mes "I was born to talk about it, but who are you talking about?";
		mes "I have so many things to talk about. I can talk about them all day long.";
		next;
		mes "[ Lazy ]";
		mes "Now, as you know, this conversation is business meeting, aren't the Vice President's underlings standing right behind you?";
		npctalk "Who else is getting paid by Rekenber here? The adventurer?","",bc_self;
		npctalk "Are you talking about me?","Ashley#171_cat",bc_self;
		next;
		mes "[ Lazy ]";
		mes "It's already known to our neighbors that Rekenber was performing illegal experiments. Maybe the people on this list could have also been involved.";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "Don't you want to clear their suspicions? Get their cooperation to know what's in your backyard?";
		mes "If it were up to me, I'd have done that already. When else would we get such an opportunity?";
		next;
		cutin "16lei_03",0;
		mes "[ Lazy ]";
		mes "What more are you hiding in your backyard? Are you not here for asking our help? If there's anything hidden over there,";
		mes "wouldn't the Vice President be in trouble?";
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "Requesting help and analyzing paperworks are separate matters.";
		next;
		cutin "16lei_03",0;
		mes "[ Lazy ]";
		mes "Is it a separate matter because you said so? When did you decide that?";
		next;
		mes "[ Lazy ]";
		mes "Now this has turned into a matter of trust, not merely a question about people missing!";
		npctalk "Do you still take me for a daisy?!","",bc_self;
		next;
		mes "[ Lazy ]";
		mes "Until we deal with these documents, how do you expect us to trust you?";
		mes "Why would you assume so? Nobody here believe you?";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "So here's the real question! How can we really cooperate with you if we don't have trust between us?";
		npctalk "The correct answer is we can't! I don't think that's possible.","",bc_self;
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "These are the official documents from the Rekenber investigation.";
		mes "Whether you believe it or not, Daisy, I don't know how else to clear your doubts.";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "So you searched into the Enterprise very thoroughly and your information is ^0000FF100% reliable.^000000";
		mes "So we have to believe it unconditionally. Isn't that strange? Do you have no evidence?";
		npctalk "I didn't know Rekenber was a fanatic religious group.","",bc_self;
		next;
		cutin "16lei_03",0;
		mes "[ Lazy ]";
		mes "I mean, if this document is credible, you're calling me a liar, Vice President!";
		next;
		cutin "16lei_01",0;
		mes "[ Lazy ]";
		mes "Oh... this is sudden. Should I seek the cooperation of the Vice President after I've been called a liar?";
		npctalk "The question is, is it reliable?","",bc_self;
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "I never called you a liar...";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "No that's not it. You're requesting our cooperation, and asking us to trust you completely without any real evidence. How can we believe you?";
		next;
		cutin "16lei_03",0;
		mes "[ Lazy ]";			
		mes "Now, even if you actively cooperate with me, it's hard for me to like this arrangement.";
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "You're repeating yourself now. I assure you, you can trust the documents.";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";				
		mes "Why would I believe in you if you don't believe in me? I'm a compassionate person, patient and very humane.";
		mes "Are your eyes so shut that you can't see what's in front of you?";
		next;
		cutin "ep171_as02",2;
		mes "[ Ashley ]";
		mes "Now you're going too far!";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "Don't worry, it's alright. You know it's all true.";
		next;
		cutin "ep171_as02",2;
		mes "[ Ashley ]";
		mes "Why, what's the matter with you?";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "Vice President, do you think that's right?";
		next;
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "........";
		next;
		cutin "16lei_02",0;
		mes "[ Lazy ]";
		mes "No? Well that's alright with me.";
		mes "I'm fine.";
		mes "I'm not blind. Even in my position, I've noticed the the Enterprise is hiding something from us!";
		next;
		cutin "16lei_03",0;
		mes "[ Lazy ]";
		mes "Anyway, Vice President, I know how people like you are, I'll give my report and I'll do things my own way.";
		npctalk "Have a good day!","",bc_self;
		next;
		mes "[ "+strcharinfo(0)+" ]";
		mes "Eh? Lazy? Where are you going!";
		cloaknpc(strnpcinfo(0),true,getcharid(0));
		sleep2 1000;
		cloaknpc("Lazy#171_cat2",false,getcharid(0));
		ep_illusion = 14;
		completequest 7864;
		setquest 17000;
		close3;
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 13");
	end;
}

pub_cat,105,58,3	script	Lazy#171_cat2	4_M_LAZY,{
	switch(ep_illusion){
		case 14:
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Ah, this is frustrating!";
			mes "Adventurer! Listen to me! Listen to me and you'll be the judge of who's right. You know what these guys have been saying?";
			unittalk getcharid(3),strcharinfo(0)+ " : It's a disgrace.",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Now, look at this ^0000FFpile of documents^000000 over here. You don't have to read it too carefully. Just look at the cover.";
			next;
			select("Rekenber... missing list..?");
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Yeah. It's a list of ^0000FFmissing people^000000 who used to work at Rekenber. I've investigated everything as much as I could.";
			unittalk getcharid(3),strcharinfo(0)+ " : What did you find?",bc_self;
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Even though I'm acquainted with the information, it's impossible to go deeper inside the Enterprise.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "If I wanted to do this, I was cautioned to proceed legally to avoid causing more frictions.";
			next;
			mes "[ Lazy ]";
			mes "I believe the president has a relationship with the government and its businesses. So they have think carefully about this matters.";
			npctalk "That's not my style.","",bc_self;
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "So when I met Kaya, I asked him to cooperate with me. You can help us in the yard, right?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Because he's a Rekenber official, it should be easy for him to find this information right?";
			next;
			select("Right.");
			mes "[ Lazy ]";
			mes "But, well, I need you to check this out and cooperate with the investigation. You know how I get when I get thrown paper from the head office.";
			npctalk "I'm do disappointed. What if the adventurer gets on a battle?","",bc_self;
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "The employees on the list are assigned to another work station and they're in constant rotation.";
			mes "Payments are also confirmed to be monthly basis.";
			next;
			mes "[ Lazy ]";
			mes "It's just common sense, why would a company go out their way to pay a salary to an unemployed person?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "I'm telling you it's common sense~";
			mes "I can say common sense in front of people who have studied hard~";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Wait, did I misunderstand the meaning of common sense?";
			mes "Did I change the definition without knowing about it?";
			unittalk getcharid(3),strcharinfo(0)+ " : Wouldn't you?",bc_self;
			npctalk "Isn't that what it means?","",bc_self;
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "So either you're lying here, or I'm the one lying. Adventurer, am I the one lying?";
			unittalk getcharid(3),strcharinfo(0)+ " : Um...",bc_self;
			npctalk "What are you worried about? I'm a very reliable person, why are you looking at me like that!","",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "To sum it all up, we've lost many contacts to Rekenber's employees. Nobody really knows what happened to them.";
			next;
			mes "[ Lazy ]";
			mes "But they have such a long history?";
			mes "The governent just now realized about this issue. There's definitely a connection between that and the missing people. That's why I decided to investigate further.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Who else would do the job if not me? That's why I have to investage.";
			mes "I have to do it in very legitimate way, Because I told him I would do it without causing friction.";
			next;
			select("Are your results any different?");
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "If you spend a long time as an adventurer, you can add 1 and 1 together. I see the scheme.";
			mes "Yes, it's real.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Yes, that's it. I'd like you to check again to figure out this mystery one and for all.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "That's why ^0000FFI don't do desk jobs^000000.";
			mes "When I look at papers, I don't know how the world outside is doing.";
			mes "I prefer going outside on the field and learn with my own eyes.";
			npctalk "Being an adventurer really suits me more.","",bc_self;
			next;
			select("Do you want to go along with the investigation?");
			mes "[ Lazy ]";
			mes "Do you think these guys who won't listen will go? Will you accompany me to search for the truth?";
			unittalk getcharid(3),strcharinfo(0)+ " : I'll check the documents from the Vice President and your finding as well.",bc_self;
			npctalk "Do adventurers have bold ideas?","",bc_self;
			next;
			select("I'll be back as soon as possible.");
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "No, no, Adventurer. You don't have to do such a thing. You just need to report the situation to me and do it the way I told you.";
			npctalk "I can sense their hate, but I can't hear them.","",bc_self;
			next;
			select("Let me speak with them");
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Yeah, well, if you want to talk, come to me anytime, but don't be too hard on yourself~ the energy and time of the adventurer is important.";
			npctalk "If you go, don't give up alright?","",bc_self;
			ep_illusion = 15;
			completequest 17000;
			setquest 17001;
			close3;
			
		case 15:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "I really like it here. Don't forget about the adventure, there's nothing to worry about.";
			close3;
			
		case 16:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "What did he say? No, right?";
			mes "See I told you. Persuading him is a waste of time. If you don't cooperate with me, there's no way I can report back to the President.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "His stiffness is stronger than bamboo. He's so rigid that his knees wouldn't bend.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "If you don't cooperate with him and do it my way from now on,";
			mes "The President will give you permission.";
			npctalk "My specialty is to go big!","",bc_self;
			next;
			mes "[ Lazy ]";
			mes "If you asked the enterprise to cooperate with us, but what are you going to do if they refused?";
			npctalk "I feel better already. Amazing~","",bc_self;
			next;
			cloaknpc("Kaya#171_cat",true,getcharid(0));
			cloaknpc("Kaya#171_cat2",false,getcharid(0));
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Hmm. Excuse me.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Have you thought about it?";
			npctalk "Have you thought about it?","",bc_self;
			next;
			cloaknpc("Ashley#171_cat",true,getcharid(0));
			cloaknpc("Ashley#171_cat2",false,getcharid(0));
			cutin "ep171_as02",1;
			mes "[ Ashley ]";
			mes "Please think it over, Vice President!";
			npctalk "Please think it over, Vice President!","Ashley#171_cat2",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "This is a waste of time, no matter how I look at it. Even if you told me a hundred times, it's not economical for me to go. But I accept your proposal anyway.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Economical? Of course it's economical. I also like being economical. So, I can do this economically on my own terms? Yeah?";
			mes "Dear Vice President?";
			npctalk "That settles it, we'll answer to the Vice President. I knew it!","",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Listen to me. I asked the government for help. I do agree that for us to trust each other, we must fully cooperate with one another.";
			next;
			cutin "ep171_kaya02",0;
			mes "[ Kaya ]";
			mes "If the only way to achieve that is by reviewing the people on the list, I will accept the condition.";
			mes "^0000FFI will accompany you and actively cooperate.^000000";
			next;
			cutin "ep171_as02",1;
			mes "[ Ashley ]";
			mes "Please reconsider, Vice President.";
			mes "You do not have to do that. I should go instead of you, no?";
			next;
			cutin "ep171_kaya02",0;
			mes "[ Kaya ]";
			mes "There is a limit to what you can do. This is my responsiblity and mine alone.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Do you even know how to travel and cooperate?";
			unittalk getcharid(3),strcharinfo(0) + " : Please! What's wrong? Let him come with us!",bc_self;
			npctalk "No, no. I admire your efforts adventurer.","",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Good. Let's forget about the past altercation and focus on the future. Thank you Vice President.";
			npctalk "Will you keep an open mind?","",bc_self;
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "While the rest are analyzing what they've brought from the lab, the Vice President and I will go deal with the list.";
			next;
			cutin "ep171_kaya02",0;
			mes "[ Kaya ]";
			mes "Before we go on, there are two ^0000FFtwo conditions^000000 for this joint investigation.";
			mes "First, please have at least ^0000FFa minimum amount of courtesy.^000000";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Oh, aren't you a ^0000FFVIP^000000?";
			mes "Okay, thank you very much, VIP.";
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "Is it a hobby of yours to provoke other people?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "If you don't like being called a VIP, then which title do you prefer?";
			unittalk getcharid(3),strcharinfo(0) + " : Pff, what the hell is wrong with you?",bc_self;
			npctalk "Why, what am I doing?","",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "... and second, I want a ^0000FFreliable person^000000 in your party.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Why?";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I will need a witness in the future.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Oh I see, so you don't believe me?";
			npctalk "Oh no~ Mother~ I'm being punished~","",bc_self;
			next;
			cutin "ep171_as02",1;
			mes "[ Ashley ]";
			mes "If that's the requirement, I'll go!";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "You're already a witness on our side. You can't be a witness.";
			next;
			select("Then I'll go.");
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Eh? Why the adventurer? If you're coming along, then you'll get to do all the fun parts...!";
			npctalk "It'll be great!","",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "If me, " + strcharinfo(0) + " and Daisy are going, it will be a fair investigation.";
			mes "Will both of our determinations combined, nothing can stop us.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Wait, but what about your guard?";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I do not need a guard. I came here by myself the first time around. I will be just fine this time too.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Very thoughtful. But you need to have a guard. It shouldn't be needed, but in case something goes wrong.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Even though I'm a very talented person, I have to prioritize my own safety first.";
			mes "Look, I can take care of myself, and If I have to, I can tag along with the adventurer, but what about a VIP?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "If you get hurt it will only cause a scandal. It would be bad! You know what I mean, right?";
			mes "Plus we might not be able to get back right away, so it might get complicated.";
			npctalk "The job is important, but protecting the VIP is also important.","",bc_self;
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "Yes, I'm definitely going!";
			npctalk "I just want to make sure you're safe!","Ashley#171_cat2",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Well then I'll bring Ashley with me...";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Also, it's really economical. Quick decision making, I like it.";
			mes "So let's start with ^0000FFEinbroch^000000 at the <NAVI>[Airport]<INFO>einbroch,42,208,0,000,0</INFO></NAVI>.";
			ep_illusion = 17;
			completequest 17002;
			setquest 17003;
			getexp 300000,300000;
			close3;
			
		case 17:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "What are you doing here?.";
			mes "Let's go to the <NAVI>[Einbroch Airport]<INFO>einbroch,42,208,0,000,0</INFO></NAVI>.";
			close3;
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 14");
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 16");
end;
}

pub_cat,109,71,3	script	Kaya#171_cat	4_EP17_KAYA,{
	switch(ep_illusion){
		case 15:
			mes "[ "+strcharinfo(0)+" ]";
			mes "Hello. I'm back is everything fine?";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Of course I can spare some time for someone who helped get back the laboratory. I really appreciate it.";
			mes "But why have you come to see me?";
			next;
			cutin "",255;
			mes "- You explain to Kaya, about what you and Lazy discussed. -";
			next;
			cutin "ep171_kaya03",2;
			mes "[ Kaya ]";
			mes "I understand what you mean, But Daisy's logic ^0000FFis too much^000000. I cannot doubt the ^0000FFcredibility of official documents,^000000 that's not just possible.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I have no intention of debating this further with you, so I'll talk to the person in charge.";
			next;
			cloaknpc("Lazy#171_cat2",true,getcharid(0));
			cloaknpc("Lazy#171_cat",false,getcharid(0));
			cutin "16lei_02",0;
			mes "[ Lazy ]";
			mes "Who's the responsible one?";
			mes "The person in front of me?";
			npctalk "Where are you looking at? There's no one there.","Lazy#171_cat",bc_self;
			next;
			cutin "16lei_01",0;
			mes "[ Lazy ]";
			mes "The president gave me his full authority on this matter.";
			next;
			cutin "ep171_kaya03",2;
			mes "[ Kaya ]";
			mes "And who are you exactly?";
			next;
			cutin "16lei_02",0;
			mes "[ Lazy ]";
			mes "I already told you before, didn't I? Does the Vice President have a bad memory?";
			next;
			cutin "ep171_kaya03",2;
			mes "[ Kaya ]";
			mes "Why would I believe a man who gave me a fake name?";
			next;
			cutin "16lei_03",0;
			mes "[ Lazy ]";
			mes "A name is just a name. If I was called Shit, would I become Shit when talking to the Vice President?";
			next;
			select("Is it your hobby to eavesdrop?");
			mes "[ Lazy ]";
			mes "Why? Isn't this where I should be?";
			mes "Is it bad to listen? Don't bother with them it's not worth your time.";
			unittalk getcharid(3),strcharinfo(0)+ " : Just let me handle it!",bc_self;
			next;
			cutin "",255;
			cloaknpc("Lazy#171_cat",true,getcharid(0));
			cloaknpc("Lazy#171_cat2",false,getcharid(0));
			mes "[ "+strcharinfo(0)+" ]";
			mes "As Lazy was saying... Even if you called Lazy by Shit, Lazy would still by Lazy.";
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "Even if there is someone introduced Lazy as Shit, would you always view him as shit for the rest of his life?";
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "Now here's what really matters. If you do not tell the truth about what really happened, you'll not be able to get their cooperation.";
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "Vice President, this is all about the Enterprise. Wouldn't it be nice to clear these doubts at once and for all, and show a better image of the Enterprise?";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I understand what you're saying, but you're wrong. We are telling you the truth and you're assuming we are lying.";
			next;
			cutin "",255;
			mes "[ "+strcharinfo(0)+" ]";
			mes "I don't know everything that Lazy knows, but he seems to have better grasp at the situation than you do, Vice President.";
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "Lazy isn't the type of person that would spend time investigating these matter for no reason.";
			unittalk getcharid(3),strcharinfo(0)+ " : If you want to build trust in the Enterprise, please reconsider.",bc_self;
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "Lazy says he cannot believe the results the Vice President has provided, but do you not believe the results Reiji provided either, correct?";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "We'd rather trust our results than those of Daisy.";
			next;
			cutin "",255;
			mes "[ "+strcharinfo(0)+" ]";
			mes "How about this then? Why don't you two, who don't trust each other, see it for yourselves, together?";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Investigate, together?";
			next;
			cutin "",255;
			mes "[ "+strcharinfo(0)+" ]";
			mes "As Lazy said, he doesn't trust your findings.";
			mes "If you can't believe in each other results, why don't you guys start from the beginning?";
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "If you both investigate the differences between the reports, you'll know for sure which is accurate. A compromise must be done here.";
			next;
			cutin "ep171_kaya02",2;
			mes "[ Kaya ]";
			mes "That's valid argument. But do I need to go too? I would prefer talking to you.";
			next;
			cloaknpc("Lazy#171_cat",false,getcharid(0));
			cloaknpc("Lazy#171_cat2",true,getcharid(0));
			cutin "16lei_02",0;
			mes "[ Lazy ]";
			mes "Can you believe what I've investigated so far? You still can't believe my findings, because you're assuming your documents are correct.";
			next;
			cutin "16lei_03",0;
			mes "[ Lazy ]";
			mes "Yeah, no. I didn't think so.";
			npctalk "The truth is overwhelming.","Lazy#171_cat",bc_self;
			next;
			select("Do you mind?");
			mes "[ Lazy ]";
			mes "I can't help it. We're wasting our time with them, why bother? What's wrong? Do you have nothing to say?";
			next;
			select("Please wait a moment, Lazy");
			mes "[ Lazy ]";
			mes "I don't have much time to wait for this sillyness.";
			next;
			cloaknpc("Lazy#171_cat",true,getcharid(0));
			cloaknpc("Lazy#171_cat2",false,getcharid(0));
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "The results will be the same no matter how many times we check them. We have a lot of other work to do.";
			next;
			cutin "",255;
			mes "[ "+strcharinfo(0)+" ]";
			mes "Vice President, you believe all the people in the Enterprise, right? But what will happen now?";
			mes "With the current situation, nobody will believe your findings.";
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "If after the joint investigation it is revealed that Lazy was wrong, then you'd simply have wasted a bit of your time, But Vice President if your papers are wrong, then it's a huge issue.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "..... Please give me a ^0000FFfew minutes^000000 to consider my options.";
			ep_illusion = 16;
			completequest 17001;
			setquest 17002;
			close3;
			
		case 16:
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Daisy's opinion is hard to accept, but the adventurer's logic is correct. I think... I'll give it a try.";
			close3;
			
		default:
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Didn't you come here to find Daisy?";
			close3;
	}
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 15");
	end;
}

pub_cat,102,62,5	script	Kaya#171_cat2	4_EP17_KAYA,{
	cutin "ep171_kaya01",0;
	mes "[ Kaya ]";
	mes "I decided to go along with the adventurer's suggestion and conduct a new investigation. But I wonder if I made the right choice.";
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

pub_cat,95,103,3	duplicate(dummynpc)	Kaya#171_cat3	4_EP17_KAYA

pub_cat,112,72,3	script	Ashley#171_cat	4_EP17_AS,{
	cutin "ep171_as01",1;
	mes "[ Ashley ]";
	mes "Daisy, I don't like his eyes and his manner of speech. Are all government people like this?";
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

pub_cat,104,63,3	script	Ashley#171_cat2	4_EP17_AS,{
	cutin "ep171_as02",1;
	mes "[ Ashley ]";
	mes "I don't know what the Vice President is thinking... But I'm going with him, even if I don't have to.";
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

//= Lighthalzen
lighthalzen,56,270,3	script	Republic Guard#171_light	4_M_EIN_SOLDIER,{
	if(ep_illusion < 10){
		npctalk "It is prohibited to go further, please step back.","",bc_self;
		end;
	}
	switch(ep_illusion){
		case 10:
			mes "[ Republic Guard ]";
			mes "I've been contacted by Tess.";
			mes "Don't worry I belong to the Secret Wing.";
			mes "Ashley and Erst went to look around this area.";
			next;
			cloaknpc("Commander Erst#171_light",false,getcharid(0));
			cloaknpc("Ashley#171_light",false,getcharid(0));
			cloaknpc("Emily#171_light",false,getcharid(0));
			npctalk "Erst : Now we can enter.","Commander Erst#171_light",bc_self;
			mes "[ Republic Guard ]";
			mes "Oh, there they are.";
			next;
			cutin "ep162_est01",2;
			mes "[ Erst ]";
			mes "You've arrived at a good time.";
			mes "I was just about to enter.";
			mes "I've already used all the guys I brought along, so I needed some back up.";
			next;
			mes "[ Erst ]";
			mes "It looks like there aren't enough to go inside...";
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "That was the plan. I told our soldiers to not harm anyone, and to keep a lookout. They won't fight carelessly.";
			next;
			mes "[ Ashley ]";
			mes "I need to know more about the current situation.";
			mes "So first things first, this operation is meant to gather more information, and then we'll launch a full attack later...";
			next;
			cutin "ep162_est01",2;
			mes "[ Erst ]";
			mes "Hehe. Right. So me and Ashley will go first.";
			mes "The rest will be waiting, and they'll come in and when we give the signal.";
			next;
			npctalk "Emily : Yes captain, don't worry!","Emily#171_light",bc_self;
			mes "[ Erst ]";
			mes "It's more important to block out all the exits so that nobody escapes.";
			mes "Everyone else, you know what to do right?";
			next;
			mes "[ Erst ]";
			mes "I'll go using another route, I'll leave it up to ashley and the adventurer.";
			mes "Let's meet inside.";
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "Yes I understand.";
			mes "Well then, I'll tell Oscar to open the door. We have to do this!";
			ep_illusion = 11;
			completequest 7861;
			setquest 7862;
			cloaknpc("Commander Erst#171_light",true,getcharid(0));
			cloaknpc("Emily#171_light",true,getcharid(0));
			close3;
			
		case 11:
			mes "[ Republic Guard ]";
			mes "The entrance is secured by Oscar who is standing up ahead the front gate.";
			mes "Me and the Rebellions will stay outside. Ashley will be inside.";
			mes "Goodluck!";
			end;
			
		default:
			end;
	}

OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 10");
	end;
}

lighthalzen,58,268,3	script	Ashley#171_light	4_EP17_AS,{
	cutin "ep171_as01",0;
	mes "[ Ashley ]";
	mes "We have to open the main gate.";
	mes "Let's open the door with Oscar.";
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

lighthalzen,54,267,5	duplicate(dummynpc)	Commander Erst#171_light	4_F_ESTLOVELOY
lighthalzen,55,265,1	duplicate(dummynpc)	Emily#171_light	4_F_ANYA

lighthalzen,259,215,3	script	Lazy#lhz	4_M_LAZY,{
	switch(ep_illusion){
		case 18:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Please gather around~ we'll check our members! Kaya! Kaya?";
			next;
			cloaknpc("Kaya#lhz",false,getcharid(0));
			cloaknpc("Ashley#lhz",false,getcharid(0));
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes ".....";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Oh, there you are! Gather around!";
			mes "There we're all together now!";
			npctalk "The adventurer is my secretary, that's my guard.","",bc_self;
			unittalk getcharid(3),strcharinfo(0) + " : I'm what?",bc_self;
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "The investigation is looking good, but could you stop this ridiculous behavior.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "I thought the VIP said there were only two conditions? Besides, everyone has already heard me.";
			npctalk "Should I do everything to please you?","",bc_self;
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "We're now officially travelers from the Schwarzwald Republic. It would be hard to look around while hiding everywhere we went to anyway.";
			next;
			mes "[ Lazy ]";
			mes "Traveling here is truly awesome~ I can feel this excitement. How do you think historians will write this day?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Kaya, relax. Leave your problems behind and just pretend you're on a holiday. You'll get a clearer perspective.";
			next;
			mes "[ Lazy ]";
			mes "First, try to look around on this trip. See how you feel about it.";
			mes "What should you do if you feel something? You should act upon it.";
			next;
			mes "[ Lazy ]";
			mes "A small report~ It's not just to admire and do nothing, right?";
			mes "Surely... there's a reason why you're traveling with us.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "By the way, did the VIP feel uncomfortable with non-fair use of the First Class? The start is uncomfortable, but the rest of the journey will be smooth.";
			next;
			mes "[ Lazy ]";
			mes "When I went by train, that felt like more First Class. Was it a good experience?";
			npctalk "The meals were delicious. And there was no sickness.","",bc_self;
			unittalk getcharid(3),strcharinfo(0) + " : I was feeling sick the whole time!",bc_self;
			next;
			mes "[ Lazy ]";
			mes "The VIP is getting familiar with us, it will give him some inspiration. Ahahaha.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "We should hurry up.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "The VIP wants to be economical. I understand. Let me explain our plan as economically as possible.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Here at Lighthalzen, the downtown and the slums coexist with one another. Both sides has structures that make it hard to easily cross the railway from the side to the other.";
			next;
			mes "[ Lazy ]";
			mes "Normally, we'd all be issued a pass to go around freely, but we don't have time for now this is the best I've managed to prepare.";
			npctalk "Also it's easier than getting into my house.","",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "What is that?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Oh, don't worry it's kind of a free pass for our agents. Of course, you don't need to know more.";
			unittalk getcharid(3),strcharinfo(0) + " : I'm just glad we don't have to go through a small hole.",bc_self;
			next;
			mes "[ Lazy ]";
			mes "Anyway we should go <NAVI>[here]<INFO>lighthalzen,336,266,0,000,0</INFO></NAVI> next.";
			ep_illusion = 19;
			completequest 17004;
			setquest 17005;
			close2;
			cutin "",255;
			questinfo_refresh();
			warp "lighthalzen",316,227;
			end;
			
		case 19:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "I've found where to go next. Let's go over <NAVI>[here]<INFO>lighthalzen,336,266,0,000,0</INFO></NAVI> next.";
			close3;
			
		case 20:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Let's go to the headquarters. The Rekenber roads are wide and gleaming~ everyone knows about the Schwarzald Republic~";
			npctalk "The Rekenber roads are wide and gleaming~ everyone knows about the Schwarzald Republic~","",bc_self;
			close3;
			
		default:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "The Rekenber roads are wide and gleaming~ everyone knows about the Schwarzald Republic~";
			close3;
	}
	end;
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 18");
end;
}

lighthalzen,336,266,3	script	Lazy#lhz2	4_M_LAZY,{
	switch(ep_illusion){
		case 19:
			cloaknpc("Kaya#lhz2",false,getcharid(0));
			cloaknpc("Ashley#lhz2",false,getcharid(0));
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "This is Pat's home. This is where Pat first got into contact with Rekenber and met a staff member.";
			sleep2 2000;
			cloaknpc("Pat#lhz",false,getcharid(0));
			cloaknpc("Rekenber's Recruiter#lhz",false,getcharid(0));
			specialeffect EF_BLUELIGHTBODY,AREA,"Pat#lhz";
			specialeffect EF_BLUELIGHTBODY,AREA,"Rekenber's Recruiter#lhz";
			sleep2 2000;
			npctalk "Here, you need to fill in all these applications for me.","Rekenber's Recruiter#lhz",bc_self;
			sleep2 2000;
			npctalk "Can I really apply for this job?","Pat#lhz",bc_self;
			sleep2 2000;
			npctalk "Anyone can do it.","Rekenber's Recruiter#lhz",bc_self;
			sleep2 2000;
			npctalk "Are you sure?","Pat#lhz",bc_self;
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Pat probably worked hard to get a chance out of poverty and live a better life. He wanted to start anew.";
			sleep2 2000;
			npctalk "Thank you so much!","Pat#lhz",bc_self;
			sleep2 2000;
			cloaknpc("Rekenber's Recruiter#lhz",true,getcharid(0));
			sleep2 500;
			cloaknpc("Pat#lhz",true,getcharid(0));
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Heyo! There you are. Mom, Dad, how are you?";
			next;
			cloaknpc("Pat's Mother#lhz",false,getcharid(0));
			cloaknpc("Pat's Father#lhz",false,getcharid(0));
			cutin "",255;
			mes "[ Mother ]";
			mes "Who...?";
			next;
			mes "[ Father ]";
			mes "Oh, he's the one who's been searching for Patrick a while ago.";
			unittalk getcharid(3),strcharinfo(0) + " : Did you come here before?",bc_self;
			npctalk "Was it only here?","",bc_self;
			next;
			mes "[ Mother ]";
			mes "Aah, that's you! Did you meet... with Pat?";
			next;
			mes "[ Father ]";
			mes "Why'd you think they lose someone who was doing well in the Enterprise?";
			next;
			mes "[ Mother ]";
			mes "No, something is definitely not right! He's not the type of person that would ^0000FFjust stop contacting us.^000000";
			next;
			mes "[ Father ]";
			mes "If you're not too busy, perhaps you could keep looking! I'm doing everything to send the paychecks all the way!";
			next;
			mes "[ Mother ]";
			mes "Eh? Of course that's important!";
			mes "It's how we're able to provide for Pat. But it's strange we haven't heard back from him yet.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Heeey~ Mom, don't fight with Dad.";
			npctalk "Who's fighting?","Pat's Father#lhz",bc_self;
			next;
			mes "[ Lazy ]";
			mes "I came here with a very high ^0000FFimportant^000000 member of your son's company. What did I tell you the other day? He's came to see the welfare of the families who have hired special talent.";
			unittalk getcharid(3),strcharinfo(0) + " : Have you already investigated this lead?",bc_self;
			npctalk "It's one of the many ways to approach people, so watch and learn. I've got of plenty of tricks in my bag.","",bc_self;
			next;
			cutin "",255;
			mes "[ Father ]";
			mes "Hello~ Is this him?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Yes, that's him. You can ask him questions as much as you'd like. He came here for this sole reason.";
			npctalk "You can use any words you want, you don't have to hesitate.","",bc_self;
			sleep2 2000;
			unittalk getcharid(3),strcharinfo(0) + " : I guess I'm the one who will have to handle this.",bc_self;
			sleep2 2000;
			npctalk "You notice things quickly.","",bc_self;
			next;
			cutin "",255;
			mes "[ Father ]";
			mes "Hello~ I don't really know where to begin... Thank you for taking in my son, my family isn't worried having enough food to survive anymore. Thank you, thank you.";
			next;
			mes "[ Father ]";
			mes "You may think my son isn't worthy but he's very good at fixing things.";
			next;
			mes "[ Father ]";
			mes "Thanks to the employment, I have a job and can feed my family now. I take pride in it.";
			next;
			mes "[ Mother ]";
			mes "But, we don't even know if he's alive or not.";
			next;
			mes "[ Father ]";
			mes "I wonder whether or not I should go to the company and ask for him directly, I'm busy at work and I can't contact him.";
			next;
			mes "[ Father ]";
			mes "I don't want to get in trouble with the company, I told my son to follow orders and not complain.";
			next;
			mes "[ Father ]";
			mes "If there's a problem on how things are going, please let us know. From his childhood, he's always been listening closely and he can fix anything.";
			next;
			mes "[ Mother ]";
			mes "Please honey! You're not asking the important questions. Is there any regulation prohibiting my son from contacting us? I haven't contacted since the day my child was hired, I can't even contact him myself...";
			npctalk "He's probably on vacation! Thank you for getting me a job!","Pat's Father#lhz",bc_self;
			sleep2 2000;
			npctalk "There's no way, they'd have never given him a day off?","Pat's Mother#lhz",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "There are no regulations to restrict personal contact. We also pay holidays based on the government's recommendation... Your son says he's on vacation.";
			next;
			cutin "",255;
			mes "[ Father ]";
			mes "So you mean to say Patrick wouldn't even come visit us?";
			next;
			mes "[ Mother ]";
			mes "Maybe he doesn't like us anymore... ^0000FFOn my first vacation^000000, I just came back to my family and talked to them.";
			next;
			mes "[ Father ]";
			mes "Oh, I can do that when I'm at work!";
			mes "What the hell are you doing with the Enterprise people! How come it's gone this far!";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Gosh! Mom, Dad! Thank you! So you can't even contact him, aren't you curious what's happening with him? I'm sure you are.";
			next;
			mes "[ Lazy ]";
			mes "We'll meet with your son, keep going with our investigation and then contact you. You can both trust me and wait. You believe me right?";
			next;
			cutin "",255;
			mes "[ Mother ]";
			mes "Oh my~ I can't believe it. Thank you so much. I'm afraid it will be hard for us to contact you...";
			next;
			mes "[ Father ]";
			mes "Aaah~ how to contact you! No matter what! Please contact us again, even if we're busy!";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Okay. Then we'll get going!";
			next;
			cutin "",255;
			mes "[ Father ]";
			mes "Take care!";
			cloaknpc("Pat's Mother#lhz",true,getcharid(0));
			cloaknpc("Pat's Father#lhz",true,getcharid(0));
			sleep2 1800;
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Did you hear all of that? As stated in the documents, they never even got a call after he joined the Enterprise. Well, I don't like seeing them like that, but I have to keep my first tourist promise.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I'm sure the employees don't come visit their home during their vacations. Isn't it a ^0000FFprivacy matter^000000 that is none of our business?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "And you think it's like that for everyone in these documents? No way? Pat is a family person, do you really think he wouldn't come back home when he's on vacation because of personal problems? Do you really believe that?";
			npctalk "You don't really believe that. Surely.","",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "How about you, guard?";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "Are you asking me?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Yes, you. Your guard doesn't look like someone who enjoys sitting in a hotel, so how about you? Don't you meet with the people you know during your vacations?";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "Yes, I often meet with my family during my vacations, sometimes even my friends.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "See? I knew it. Who wouldn't do that? Okay sure. Maybe one guy out of ten.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "The company doesn't investigate private matters. It's private for a reason. Ask yourself if you'd want someone else to look into your private matters.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Aah~ Do you want to meet with them for a few more minutes~ Will the VIP come here again?";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I think I heard as much as I need to here. We'll find the rest of the information in the headquarters.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "The people who made these documents don't know anything about Pat. It's not just one or two persons on this list. Should you really listen to one person?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Aren't you tired of walking this path narrow, steep path?";
			npctalk "Ahahaha. The VIP has never heard anything heavier than a gold spoon.","",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Are you tired already? There are people like this everyday. As your people suffer, more people suffer, so much that you can't even recognize pain.";
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "Are you giving me orders?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Hello~ I'm just a tourist guide, how can I give you orders. The judgement is done by the VIP's intellect, reasoning and conscience~";
			next;
			mes "[ Lazy ]";
			mes "Alright! We're going to follow up with Pat, so the tour's next location will be at the <NAVI>[Headquarters]<INFO>lighthalzen,107,165,0,000,0</INFO></NAVI>.";
			ep_illusion = 20;
			completequest 17005;
			setquest 17006;
			close2;
			cutin "",255;
			questinfo_refresh();
			warp "lighthalzen",251,215;
			end;
			
		case 20:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Alright! We're going to follow up with Pat, so the tour's next location will be at the <NAVI>[Headquarters]<INFO>lighthalzen,107,165,0,000,0</INFO></NAVI>.";
			close2;
			cutin "",255;
			warp "lighthalzen",251,215;
			end;			
			
		default:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "The Rekenber roads are wide and gleaming~ everyone knows about the Schwarzald Republic~";
			close3;
	}
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 19");
	end;
}

lighthalzen,108,163,3	script	Lazy#lhz_rek	4_M_LAZY,{
	switch(ep_illusion){
		case 20:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Adventurer! You're here! Who else would it be?";
			next;
			cloaknpc("Kaya#lhz3",false,getcharid(0));
			cloaknpc("Ashley#lhz3",false,getcharid(0));
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "You're finally here. Am I too fast for you? Or do you think perhaps it's because the VIP's shoes are not suited for long distances?";
			unittalk getcharid(3),strcharinfo(0) + " : Why are we here?!",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "We're finally here at Rekenber.";
			next;
			specialeffect EF_BLUELIGHTBODY,AREA,"Pat#lhz2";
			cloaknpc("Pat#lhz2",false,getcharid(0));
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "When Pat stood in front of the building, he was probably relieved.";
			mes "The job in the slums wasn't that much different than the one at Rekenber.";
			npctalk "Really... Rekenber... I... I'm here now...!","Pat#lhz2",bc_self;
			next;
			cutin "",255;
			mes "[ Protester ]";
			mes "Rekenber, ^0000FFexplain!^000000";
			next;
			cloaknpc("Pat#lhz2",true,getcharid(0));
			cloaknpc("Protester#lhz",false,getcharid(0));
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Explanation?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Ah! Well done. I wanted to introduce her to you. She's the fiance of ^0000FFanother missing person^000000 on the list.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Her fiance was hired by the Rekenber, and then she wasn't able to contact him anymore. Of course, she tried to contact the company and asked what was going on, but what did they tell her?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Hey Eva! Hello! Come over here, over here!";
			next;
			cutin "",255;
			mes "[ Protester ]";
			mes "Daisy? Hi. Do you have more information on what happened?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Oh, that? I don't know yet, but I came here with the Vice President to find out.";
			next;
			cutin "",255;
			mes "[ Protester ]";
			mes "The Vice... President? This person?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Yeah, that's right. You have something to tell him? Go ahead!";
			mes "This will be good, I don't regret getting out of bed today!";
			npctalk "This guy, what is he thinking?","Ashley#lhz3",bc_self;
			unittalk getcharid(3),strcharinfo(0) + " : I... I feel this is my fault.",bc_self;
			next;
			cutin "",255;
			mes "[ Eva ]";
			mes "What happened to Marcus? Give me my Marcus back! It's been 2 years since I haven't heard from Marcus!";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "You're looking for Marcus? Mar...cus... Holzman. He's from the East of Lighthalzen...";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Oh, what a coincidence. He's also from the Lighthalzen slums!";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Maybe he doesn't want to contact you anymore?";
			next;
			cutin "",255;
			mes "[ Eva ]";
			mes "Marcus would never do that to me! My Marcus... Marcus...";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "No matter what the truth is, I don't know a third person with the same issue as yours.";
			next;
			cutin "",255;
			mes "[ Eva ]";
			mes "Even if Marcus's thoughts about me had changed, he's not the only one!";
			mes "Most of the people from the slums that are hired by the Rekenber ^0000FFcannot be reached anymore.^000000";
			next;
			mes "[ Eva ]";
			mes "Do you really think everyone would change their minds like that? To their family? Their friends? Even lovers? It's a bigger issue!";
			mes "What the hell did Rekenber do with their employees?!";
			npctalk "Look. It's the same as I said.","",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I would like to know more details about this. Let's go back. If we make a disturbance here, they'll call the police.";
			npctalk "Vice President, I'd prefer if you went inside.","",bc_self;
			next;
			cutin "",255;
			mes "[ Eva ]";
			mes "What? Do you want to throw me out?";
			mes "Am I a problem to you? Do you think I'll give up easily? I will keep coming until I find Marcus!";
			npctalk "I will remember your face!! Don't think you'll be safe forever! Be careful at night!","Protester#lhz",bc_self;
			next;
			cloaknpc("Protester#lhz",true,getcharid(0));
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "She said he saw the VIP...";
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "What are you trying to say?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "You're a VIP. You're so beautiful, I'm very impressed. Tsk. Tsk. Tsk.";
			npctalk "I am touched right now, I got tears in my eyes.","",bc_self;
			next;
			mes "[ Lazy ]";
			mes "Listen carefully. As I said before, joining Rekenber is the envy of most people in the slums. If you can't imagine how excited it is for them, then maybe you can't think.";
			npctalk "With that smart head of yours.","",bc_self;
			next;
			mes "[ Lazy ]";
			mes "For such people, Rekenber has been giving out special gifts as part of social welfare, don't you know about it. Rekenber is tricking people.";
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "Are you disrespecting the company's welfare business? I get the same treatment as those who have been specially selected.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "That's not what I'm saying VIP. The secretary here knows too. Do you really not know? Are you pretending?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Have you seen Rekenber's criteria for their special offer?";
			mes "People who have healthy body and no families. Among them, why would they only pick the poorest?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "What do you think this means? Why only people with good health~ or no money~ then they disappear only to get paychecks to their house~";
			npctalk "Ohh~ I'm really curious~","",bc_self;
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "But there's a single missing person around me.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Woah, is that really surprising?";
			mes "You're a guard? Your guard is from the borders of Rune-Midgard, right?";
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "How did you know that?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "It's easy to recognize a person from their personality and their tone of voice. It's easy for anyone to know, but I can see it just by looking at your face.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Speaking of personalities, I'm like a guard myself and our spirits can't be broken. You can't break me like a wheel, I'll fight back.";
			next;
			cutin "ep171_as02",0;
			mes "[ Ashley ]";
			mes "I would rather use force than make compromises.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Hah! That's it, that's the spirit. The type that day to day! You would have never allowed your friends to have gone missing just like that. Your personality is what saved our guard, for now anyway.";
			next;
			mes "[ Lazy ]";
			mes "Anyway do you have a special unit in your guard? I know the answer already.";
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "Yes... we do.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "I knew it. The VIP says you all get the same treatment. But he won't give security to the people of the slums.";
			mes "The people in your team are the kind of people who don't go missing.";
			next;
			mes "[ Lazy ]";
			mes "Simply because it's more troublesome to make a guard disappear. It makes more noises.";
			next;
			mes "[ Lazy ]";
			mes "With the money and the welfare paychecks, isn't it easier to just make someone disappear from a vulnerable family and then make their voices unheard?";
			npctalk "Woah~ I told you~ It's scary~","",bc_self;
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "Do you even know what you're insuating now? It's all speculations!";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Do you really know what I'm thinking?";
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "Come in and check it out yourself!";
			mes "Let's see why they never made contact. I don't know what they did during their vacations, but we can see where they are now.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Hah, this guy, he's still all about privacy. Are statistics and odds not part of the economy? Why do all of these people go and never contact their house again?";
			next;
			select("Why are they giving their salaries?");
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Our adventurer asked a good question. They are almost all from the slums. In Rekenber, they offer you accomodations, with meals and lodging, you hardly have to spend any money at all.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "If the adventurer is from a poor family, and you have to support it, would you spare money for your meals?";
			next;
			select("I would send everything.");
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "These accomodations for the low-income classes is Rekenber's contribution to society. We do our best!";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Ahah! Was I not polite enough? Our VIP is getting angry~ But the adventurer and I have gone to many places before, we know these things.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "It's an illegal laboratory. You know what an illegal laboratory is?";
			mes "It would be used for illegal experiments with human life? Used like a lab rats?";
			next;
			cutin "ep171_as02",1;
			mes "[ Ashley ]";
			mes "Aren't you imagining too much now.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Our guard here and the VIP are not imaginative? I know you don't see to look at what's in front of you, but look at the reality of the situation here.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Do you know what your colleagues ate and what they were doing before the day was over?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Did the VIP know about the disappearance of his employees until I pushed to investigate about it?";
			next;
			cutin "ep171_kaya03",0;
			mes "[ Kaya ]";
			mes "I still cannot conclude that they're missing.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Alright, I see. Let's call it a problem, not a missing person. Do you feel better then? If it makes it easier for you, I'll call it that. Do you even want to solve this problem in a positive light?";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Of course.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Perfect, I had hoped you'd say that. I'm glad to see you're not angry anymore. So open your mind~ don't get angry~ breath slowly~ exhale~";
			next;
			mes "[ Lazy ]";
			mes "If you're right, then let's check it out at the <NAVI>[Headquarters]<INFO>lhz_in01,107,137,0,000,0</INFO></NAVI>.";
			ep_illusion = 21;
			completequest 17006;
			setquest 17007;
			close2;
			cutin "",255;
			cloaknpc("Kaya#lhz3",true,getcharid(0));
			cloaknpc("Ashley#lhz3",true,getcharid(0));
			end;
			
			
		case 21:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Come on, get inside the <NAVI>[Headquarters]<INFO>lhz_in01,107,137,0,000,0</INFO></NAVI>!";
			close3;
			
		default:
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "The Rekenber roads are wide and gleaming~ everyone knows about the Schwarzald Republic~";
			close3;
	}
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 20");
	end;
}

lighthalzen,256,215,5	duplicate(dummynpc)	Kaya#lhz	4_EP17_KAYA
lighthalzen,255,216,5	duplicate(dummynpc)	Ashley#lhz	4_EP17_AS
lighthalzen,336,264,3	duplicate(dummynpc)	Kaya#lhz2	4_EP17_KAYA
lighthalzen,335,261,1	duplicate(dummynpc)	Ashley#lhz2	4_EP17_AS
lighthalzen,331,262,5	duplicate(dummynpc)	Pat#lhz	4_M_REPAIR
lighthalzen,332,260,5	duplicate(dummynpc)	Rekenber's Recruiter#lhz	4_F_HUWOMAN
lighthalzen,331,263,7	duplicate(dummynpc)	Pat's Mother#lhz	4_F_EINWOMAN
lighthalzen,333,264,7	duplicate(dummynpc)	Pat's Father#lhz	4_M_MIDDLE1
lighthalzen,104,163,5	duplicate(dummynpc)	Kaya#lhz3	4_EP17_KAYA,{ end; }
lighthalzen,103,165,5	duplicate(dummynpc)	Ashley#lhz3	4_EP17_AS,{ end; }
lighthalzen,106,162,1	duplicate(dummynpc)	Pat#lhz2	4_M_REPAIR,{ end; }
lighthalzen,106,162,5	duplicate(dummynpc)	Protester#lhz	4_F_ZONDAGIRL,{ end; }

//= Rekenber HQ
lhz_in01,107,137,5	script	Staff#rek	4_F_01,{
	switch(ep_illusion){
		default:
			mes "[ Staff ]";
			mes "Do you need help with something?";
			close;
			
		case 21:
			mes "[ Staff ]";
			mes "Hello, how may I help you?";
			next;
			cloaknpc("Kaya#rek",false,getcharid(0));
			cloaknpc("Ashley#rek",false,getcharid(0));
			cloaknpc("Lazy#rek",false,getcharid(0));
			mes "[ Lazy ]";
			mes "We've finally enter the Rekenber's headquarters. I wonder if Pat was relieved when he first passed through this door. Where did he go next?";
			sleep2 1000;
			specialeffect EF_BLUELIGHTBODY,AREA,"Pat#rek";
			cloaknpc("Pat#rek",false,getcharid(0));
			sleep2 2000;
			npctalk "I... I... I...","Pat#rek",bc_self;
			sleep2 2000;
			npctalk "Hi, what can I do for you?","Staff#rek",bc_self;
			sleep2 2000;
			npctalk "I work here... I'm new... where should I go...","Pat#rek",bc_self;
			sleep2 2000;
			npctalk "What is your name?","Staff#rek",bc_self;
			sleep2 2000;
			npctalk "My name is Patrick Kaufman.","Pat#rek",bc_self;
			sleep2 2000;
			npctalk "Patrick... Kaufman. Yes, you are confirmed.","Staff#rek",bc_self;
			sleep2 2000;
			npctalk "I'm really hired, right?","Pat#rek",bc_self;
			sleep2 2000;
			npctalk "Of course. You're on the list of new employees. You can go ahead on the 2nd floor, in the OT and listen to the training.","Staff#rek",bc_self;
			sleep2 2000;
			npctalk "Thank you, Thank you!","Pat#rek",bc_self;
			sleep2 2000;
			cloaknpc("Pat#rek",true,getcharid(0));
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Do all employees go through OT?";
			mes "I thought they would assign them to their department directly.";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "Ah yes, you're right. For the special talented people, they must go through OT first and then they are assigned to their own respective department.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Why is that?";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "It's a system based on their ^0000FFplace of origin^000000. There are many people who are not familiar with the corporate culture. After many trials and errors, the new employees are now required to go through OT.";
			npctalk "The exact same treatment, huh?","Lazy#rek",bc_self;
			unittalk getcharid(3),strcharinfo(0) + " : Shush! Lower your voice!",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Let's go the <NAVI>[Conference Room]<INFO>lhz_in01,162,257,0,000,0</INFO></NAVI> where Pat started his life at Rekenber.";
			ep_illusion = 22;
			completequest 17007;
			setquest 17008;
			close2;
			cutin "",255;
			cloaknpc("Kaya#rek",true,getcharid(0));
			cloaknpc("Ashley#rek",true,getcharid(0));
			cloaknpc("Lazy#rek",true,getcharid(0));
			questinfo_refresh();
			end;
			
		case 22:
			mes "[ Staff ]";
			mes "I think the others went to the <NAVI>[Conference Room]<INFO>lhz_in01,162,257,0,000,0</INFO></NAVI>, where the meetings are held. Shouldn't you be going?";
			end;
	}
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 21");
	end;
}

lhz_in01,163,258,5	script	Staff#rek2	4_M_EINMAN,{
	switch(ep_illusion){
		case 22:
			setpcblock PCBLOCK_ALL, true;
			specialeffect EF_BLUELIGHTBODY,AREA,"Staff#rek3";
			cloaknpc("Staff#rek3",false,getcharid(0));
			npctalk "With this, we will have completed the pre-training for the employees.","Staff#rek3",bc_self;
			sleep2 2000;
			npctalk "If you're new around here, you can get directions from the person in charge of the assignemnts.","Staff#rek3",bc_self;
			sleep2 2000;
			npctalk "Facility maintenance department, come with me!","",bc_self;
			sleep2 2000;
			cloaknpc("Staff#rek3",true,getcharid(0));
			specialeffect EF_BLUELIGHTBODY,AREA,"Pat#rek2";
			cloaknpc("Pat#rek2",false,getcharid(0));
			sleep2 2000;
			npctalk "That's me!","Pat#rek2",bc_self;
			sleep2 2000;
			npctalk "What am I supposed to do now?","Pat#rek2",bc_self;
			sleep2 2000;
			npctalk "I looked at your resume and I saw a lot potential. Please remember. You have to be fast and accurate. You don't worry too much about the details.","",bc_self;
			sleep2 2000;
			npctalk "I'm very confident!","Pat#rek2",bc_self;
			sleep2 2000;
			npctalk "I like your response, we need more people like you!","",bc_self;
			sleep2 2000;
			cloaknpc("Pat#rek2",true,getcharid(0));
			cloaknpc("Lazy#rek2",false,getcharid(0));
			cloaknpc("Kaya#rek2",false,getcharid(0));
			cloaknpc("Ashley#rek2",false,getcharid(0));
			setpcblock PCBLOCK_ALL, false;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Let's ask this guy for information.";
			next;
			mes "[ Lazy ]";
			mes "Do you know Kaufman? Patrick Kaufman.";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "Who are you?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "The Vice President is looking for Kaufman.";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "I see, what is the purpose. And... who are you again?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Are you the secretary of the Vice President?";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "What are you talking about? Did your secretary get hit on the head? You sound like an outsider?";
			npctalk "Are you... playing with me?","",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I'm looking for Patrick Kaufman.";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "You, who are you... ? I've seen that face before... are you...?";
			npctalk "Think, come on, think.","",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "He is your Vice President.";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "Aaah! Yes, right, right!!! ...Vice President? Oh, hello!";
			npctalk "Is this guy really the Vice President?","",bc_self;
			npctalk "I already told you that! I'm not lying.","Lazy#rek2",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Do you know anything about Patrick Kaufman?";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "Patrick Kaufman... I know him. He's a good friend of mine. He has rough hands but his work is fast and accurate.";
			mes "I tried to keep him around longer, but they took him to the lab.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "The laboratory? Was it Regenschirm?";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "Yes, there. The newcomers must be in the company for ^0000FFat least a whole year^000000 before they can be sent to another department or a new workplace, unless they are given a ^0000FFspecial request.^000000";
			next;
			mes "[ Staff ]";
			mes "But why would I send newcomers in the first place? I ignored the requests even though it came from above. But even so, some of the newcomers here were sent elsewhere anyway.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Why?";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "Well you see... I need mor epeople for repairs. There's always something broken, so I always need more manpower. But recently,";
			mes "There's been ^0000FFa  lot more workforce requested.^000000";
			npctalk "It's kind of a problem to always send away the best workers everyday.","",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Do you know why so many people were drafted?";
			npctalk "Do you know why so many people were drafted?","Lazy#rek2,",bc_self;
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "I don't know for sure. Many people in our department get injured while working, and our newcomers are all very strong.";
			mes "They only take those who are ^0000FFvery good at their job.^000000";
			npctalk "They're like ghosts, they take them away as soon as they arrive.","",bc_self;
			next;
			mes "[ Staff ]";
			mes "But if you are pressured from above, you have to abide and give them the workforce, right?";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Which laboratory were they sent to?";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "The annex one. Oh, do you want to go? I haven't been there in a while, it's quite hard to get inside. If you don't mind, could you send people back here?";
			mes "Anyway, please be careful, it is a dangerous place.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Ooh.. You cannot be transferred at least until a whole year, unless you are given ^0000FFan unusual request.^000000";
			mes "But Pat didn't get neither one of these reasons. Is it really a laboratory?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Did you know this VIP? was there anything about this in your documents? Why did the lab only take healthy and you people?";
			npctalk "Ooooh~ What is the reason~ I'm so curious~","Lazy#rek2",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I need to know why they broke the contract rules.";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "I was in charge of Regenschirm, but I've never seen Patrick Kaufman.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Yeah? You're getting curious too now, aren't you! Is that right?";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "I will guide you, follow me. Let's go to <NAVI>[Regenschirm]<INFO>rgsr_in,157,84,0,000,0</INFO></NAVI>.";
			ep_illusion = 23;
			completequest 17008;
			setquest 17009;
			close2;
			cutin "",255;
			cloaknpc("Lazy#rek2",true,getcharid(0));
			cloaknpc("Kaya#rek2",true,getcharid(0));
			cloaknpc("Ashley#rek2",true,getcharid(0));
			end;
			
		case 23:
			mes "[ Staff ]";
			mes "People are waiting for you at the <NAVI>[laboratory]<INFO>rgsr_in,157,84,0,000,0</INFO></NAVI>, why don't you go aswell?";
			end;
			
		default:
			mes "[ Staff ]";
			mes "There doesn't seem to be any room left.";
			close;
	}
	end;

OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 22");
	end;
}

lhz_in01,80,210,5	script	Secretary#rek	4_M_RUSMAN1,{
	switch(ep_illusion){
		case 25:
			mes "[ Secretary ]";
			mes "Hey, where are you going!";
			next;
			select("Are you talking to us?");
			cloaknpc("Lazy#rek3",false,getcharid(0));
			cloaknpc("Kaya#rek3",false,getcharid(0));
			cloaknpc("Ashley#rek3",false,getcharid(0));
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Adventurer, let's go quickly? Let's go together.";
			npctalk "Don't forget we have a senior here, so you have to worry about your behavior.","Lazy#rek3",bc_self;
			next;
			cutin "",255;
			mes "[ Secretary ]";
			mes "You came all the way to the office, what's going in? You left me alone in here and then just disappeared.";
			mes "Why are you sneaking in?";
			unittalk getcharid(3),strcharinfo(0) + " : Oh, you're not talking to me.",bc_self;
			npctalk "Who would talk to an adventurer like you in here?","Lazy#rek3",bc_self;
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Do you know who's the gentlemen next to me?";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Yes, he is my secretary.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Ah! Nice to meet you. My name is Daisy. I'm an old friend of the Vice President.";
			next;
			cutin "",255;
			mes "[ Gray ]";
			mes "Hello there. I'm called Gray Earl.";
			mes "I'm usually not in these places, we should continue this meeting in the Vice President's office.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "You don't have to. Here will be just fine. What are you doing in this place anyway? Were you waiting for someone?";
			next;
			cutin "",255;
			mes "[ Gray ]";
			mes "Yes, I noticed something odd about the Vice President's absence, so I went out to see what was going on.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "If you keep waiting outside like that, don't you think it looks even more suspicious?";
			next;
			cutin "",255;
			mes "[ Gray ]";
			mes "So you were hiding on purpose. Can you tell what this was all about?";
			mes "Why all the secrecy?";
			npctalk "The deal was to hide.","Lazy#rek3",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "That was our plan. I'm cooperating with these people.";
			next;
			cutin "",255;
			mes "[ Gray ]";
			mes "Cooperating.. with them..?!";
			mes "I didn't think we'd be friends with these people again.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Why? Can't we be friends? You! You'll have to explain yourself!";
			next;
			cutin "",255;
			mes "[ Gray ]";
			mes "You don't seem that old.";
			npctalk "Oh, you look younger than me? Ahahaha! I think I'm really starting to like this guy?","Lazy#rek3",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "You don't need to know more about this. The less you know, the better. When we finish the investigation, we'll let you know.";
			next;
			cutin "",255;
			mes "[ Gray ]";
			mes "Yes, sir.";
			unittalk getcharid(3),strcharinfo(0) + " : Are you sure keeping secrets is a good idea?",bc_self;
			sleep2 2000;
			npctalk "Shush~ You're new at this. Give me some time to work this out.","Lazy#rek3",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "So, do you know who's in charge of moving the workforce from one department to another? Is it someone you trust?";
			next;
			cutin "",255;
			mes "[ Gray ]";
			mes "Do you want the employee transfer logs? They are kept in the document storage room.";
			next;
			mes "[ Gray ]";
			mes "If you want to uncover secrets, it would wiser to straight to the document storage room and search for the documents yourself than going through the Human Resource department.";
			npctalk "Eh.. I really like this person! He's one out of thn that has a head on his shoulder!","Lazy#rek3",bc_self;
			sleep2 2000;
			unittalk getcharid(3),strcharinfo(0) + " : That must be why he's the secretary of the Vice President.",bc_self;
			next;
			mes "[ Gray ]";
			mes "Let me tell you where you can find these trustworthy documents.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I know already.";
			next;
			cutin "",255;
			mes "[ Gray ]";
			mes "Alright, then plesae be careful.";
			mes "There are many eyes around here. You know what I mean, right?";
			npctalk "Perfect to the end.","Lazy#rek3",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Let's go the <NAVI>[Document Storage Room]<INFO>lhz_in01,32,264,0,000,0</INFO></NAVI>.";
			ep_illusion = 26;
			completequest 17011;
			setquest 17012;
			close2;
			cutin "",255;
			cloaknpc("Lazy#rek3",true,getcharid(0));
			cloaknpc("Kaya#rek3",true,getcharid(0));
			cloaknpc("Ashley#rek3",true,getcharid(0));
			questinfo_refresh();
			end;
		
		case 26:
			mes "[ Gray ]";
			mes "Go to the <NAVI>[Document Storage Room]<INFO>lhz_in01,32,264,0,000,0</INFO></NAVI>,";
			mes "go quickly before you get noticed.";
			end;
			
		default:
			mes "[ Gray ]";
			mes "Don't you  have something else to do.";
			close;
	}
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 25");
	end;
}

lhz_in01,32,264,5	script	Staff#rek4	4_M_HUMAN_02,{
	if(ep_illusion == 26){
		mes "[ Staff ]";
		mes "Hello, this is the document storage room.";
		next;
		cloaknpc("Lazy#rek4",false,getcharid(0));
		cloaknpc("Kaya#rek4",false,getcharid(0));
		cloaknpc("Ashley#rek4",false,getcharid(0));
		mes "[ Staff ]";
		mes "Ah! I see. You're looking for Patrick Kaufman's transfer logs?";
		npctalk "It feels good to smell the books here. My dream was to be a librarian. I should do that from now on.";
		unittalk getcharid(3),strcharinfo(0) + " : I don't that would fit you...",bc_self;
		next;
		cutin "ep171_kaya01",0;
		mes "[ Kaya ]";
		mes "Yes, that's why we're here. Have you found what we're looking for?";
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "Patrick Kaufman. Transfer 12-4332.";
		next;
		mes "[ Staff ]";
		mes "He was working as part of the facility maintenance department and then trasnferred to a new facility.";
		mes "It says the director, McDonald, came here directly and gave a list of people to transfer.";
		next;
		cutin "ep171_kaya01",0;
		mes "[ Kaya ]";
		mes "Do you still have that list?";
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "Oh, that? Wait a minute...";
		next;
		mes "[ Staff ]";
		mes "Oh, there it is. I found it.";
		next;
		cutin "ep171_kaya01",0;
		mes "[ Kaya ]";
		mes "Daisy, can you compare the list please.";
		next;
		cutin "16lei_02",2;
		mes "[ Lazy ]";
		mes "Hmm.. there are many overlap with the names from both lists. I expected as such... but I'm confused.";
		next;
		cutin "ep171_kaya01",0;
		mes "[ Kaya ]";
		mes "Does Kaufman still work at McDonald's laboratory?";
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "Well... the fact is, some of the facility maintenance employees work outside of the labs.";
		mes "Patrick was from the same department, so maybe it was the same for him.";
		next;
		cutin "ep171_kaya01",0;
		mes "[ Kaya ]";
		mes "I've been told we are not allowed to transfer people until at least a whole year, but what is the reason why Kaufman was transferred?";
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "Well... there's reason to do that here. Once a request is received from the lab, we approve it. It's a top priority.";
		next;
		cutin "ep171_kaya01",0;
		mes "[ Kaya ]";
		mes "So where is Kaufman right now?";
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "As I told you before, I work around the clock... there are many laboratories here and there, I'm not sure which ones are still operational or not.";
		next;
		mes "[ Staff ]";
		mes "We don't keep track of all the trips and movements inside the headquarters. I hear a lot, though.";
		mes "The detailed records can be found inside the lab he is in, or another lab perhaps.";
		next;
		cutin "16lei_01",2;
		mes "[ Lazy ]";
		mes "How was his vacations? Did he rest well?";
		npctalk "I would have so much trouble to work here that I would never rest.","Lazy#rek4",bc_self;
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "On vacation... he has already used al of his days. Well... he drove out at the end of the year.";
		npctalk "Oh~ he wasn't able to rest, until the end of the year. Rekeber is quite a place~","Lazy#rek4",bc_self;
		npctalk "Absolutely not!","Ashley#rek4",bc_self;
		next;
		cutin "16lei_02",2;
		mes "[ Lazy ]";
		mes "And where did he go during his vacations? I already know the answer, but there is someone here who doesn't believe me.";
		npctalk "Tell me what he did~","Lazy#rek4",bc_self;
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "We do not control how and where the employees spend their private time.";
		next;
		cutin "ep171_kaya01",0;
		mes "[ Kaya ]";
		mes "Just one more check. Marcus Holzman is on the list. Where is he working now?";
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "Let's see, Marcus Holzman? Wait...";
		sleep2 2000;
		//progressbar_npc "00FF00",2;
		next;
		mes "[ Staff ]";
		mes "Well, Holzman went to Sinclair's laboratory.";
		next;
		cutin "16lei_02",2;
		mes "[ Lazy ]";
		mes "Did he use all of his vacations as well?";
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "Yes... He drove out at the end of the year and use all of his vacations days...";
		next;
		cutin "ep171_kaya01",0;
		mes "[ Kaya ]";
		mes "Where is the laboratory?";
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "Let's see... the lab is on the outside of Einbroch's outer zone.";
		mes "McDonald lab is located at ^0000FFSector 01 - Section 95-146 in the Einbroch Mountains^000000 and Sinclair's lab is located at Zone 11 - Sector 45-156 in the Einbroch Mountains.";
		next;
		cutin "16lei_02",2;
		mes "[ Lazy ]";
		mes "And there it goes. Of course. I also know the asnwer, but I'll ask you anyway, are Patrick and Marcus still working at Rekenber?";
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "Of course. They are being paid for work. If you leave, you wouldn't get paid anymore, right?";
		next;
		cutin "16lei_02",2;
		mes "[ Lazy ]";
		mes "Of course, that's common sense~";
		npctalk ".....","Kaya#rek4",bc_self;
		npctalk "Are we really going back to this?","Ashley#rek4",bc_self;
		unittalk getcharid(3),strcharinfo(0) + " : Don't worry, he will tire himself out after a while.",bc_self;
		next;
		cutin "16lei_01",2;
		mes "[ Lazy ]";
		mes "Now let's head to these new laboratories. There's probably a lot more we can find out over there.";
		next;
		select("How are we doing this?");
		cutin "16lei_03",2;
		mes "[ Lazy ]";
		mes "We can all go together. We came here for this reason.";
		next;
		cutin "ep171_as01",0;
		mes "[ Ashley ]";
		mes "How about we save some time and share information afterwards? Let's split and meet again at a specific location.";
		next;
		cutin "16lei_01",2;
		mes "[ Lazy ]";
		mes "That's a good idea. Then me and you will go to Sinclair's laboratory together.";
		mes "The adventurer will go to McDonald's laboratory with the VIP. When we finish the investigation, we'll meet you back over at McDonald's lab.";
		next;
		cutin "ep171_as02",0;
		mes "[ Ashley ]";
		mes "Why? Why am I going with you? Isn't it better for me to go back with the Vice President?";
		next;
		cutin "16lei_02",2;
		mes "[ Lazy ]";
		mes "Have you forgotten? The Vice PResident wants to do this operation as unbiased as possible.";
		mes "Would you believe the findings of me and the adventurer?";
		npctalk "I'm the image of distrust~","Lazy#rek4",bc_self;
		next;
		cutin "16lei_03",2;
		mes "[ Lazy ]";
		mes "Do you want to give the Vice President a reason to be suspicious? We can't allow that?";
		npctalk "It shouldn't be hard with the guard.","Lazy#rek4",bc_self;
		next;
		cutin "ep171_kaya01",0;
		mes "[ Kaya ]";
		mes "I'm fine with Daisy's idea. It makes the most sense.";
		next;
		cutin "ep171_as02",0;
		mes "[ Ashley ]";
		mes "Vice President! The reason I'm here is to protect you!";
		next;
		cutin "ep171_kaya01",0;
		mes "[ Kaya ]";
		mes "I won't say it twice.";
		npctalk "Alright...","Ashley#rek4",bc_self;
		next;
		cutin "16lei_01",2;
		mes "[ Lazy ]";
		mes "Let's go now. You're heading for the <NAVI>[McDonald Laboratory]<INFO>ein_fild01,95,146,0,000,0</INFO></NAVI>, wait for us when you're done.";
		ep_illusion = 27;
		completequest 17012;
		setquest 17013;
		next;
		cutin "",255;
		mes "[ Staff ]";
		mes "Please have a look. If you need anything, let me know!";
		close2;
		cloaknpc("Lazy#rek4",true,getcharid(0));
		cloaknpc("Kaya#rek4",true,getcharid(0));
		cloaknpc("Ashley#rek4",true,getcharid(0));
		end;
	}
	if(ep_illusion == 27){
		mes "[ Staff ]";
		mes "<NAVI>[McDonald Laboratory]<INFO>ein_fild01,95,146,0,000,0</INFO></NAVI> is located in Einbroch, at the outer zone. Please be careful, it is a dangerous area.";
		end;
	}
	mes "[ Staff ]";
	mes "If you have a document or a book to find, please go see the staff member at the entrance.";
	end;
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 26");
end;
}


lhz_in01,105,134,7	duplicate(dummynpc)	Lazy#rek	4_M_LAZY
lhz_in01,108,135,1	duplicate(dummynpc)	Pat#rek	4_M_REPAIR
lhz_in01,109,134,1	duplicate(dummynpc)	Kaya#rek	4_EP17_KAYA
lhz_in01,109,136,3	duplicate(dummynpc)	Ashley#rek	4_EP17_AS

lhz_in01,161,255,7	duplicate(dummynpc)	Lazy#rek2	4_M_LAZY
lhz_in01,168,257,5	duplicate(dummynpc)	Staff#rek3	4_F_CHNDOCTOR
lhz_in01,162,255,1	duplicate(dummynpc)	Pat#rek2	4_M_REPAIR
lhz_in01,164,255,1	duplicate(dummynpc)	Kaya#rek2	4_EP17_KAYA
lhz_in01,164,256,3	duplicate(dummynpc)	Ashley#rek2	4_EP17_AS

lhz_in01,82,209,3	duplicate(dummynpc)	Lazy#rek3	4_M_LAZY
lhz_in01,81,208,1	duplicate(dummynpc)	Kaya#rek3	4_EP17_KAYA
lhz_in01,82,207,1	duplicate(dummynpc)	Ashley#rek3	4_EP17_AS

lhz_in01,33,263,3	duplicate(dummynpc)	Lazy#rek4	4_M_LAZY
lhz_in01,33,262,1	duplicate(dummynpc)	Kaya#rek4	4_EP17_KAYA
lhz_in01,34,262,3	duplicate(dummynpc)	Ashley#rek4	4_EP17_AS

//= Regenschirm Laboratory
rgsr_in,161,85,3	script	Laboratory Staff#rgsr_in	4_LGTSCIENCE,{
	switch(ep_illusion){
		case 23:
			mes "[ Staff ]";
			mes "This place is restricted from outsiders, please leave.";
			next;
			cloaknpc("Lazy#rgsr_in",false,getcharid(0));
			cloaknpc("Kaya#rgsr_in",false,getcharid(0));
			cloaknpc("Ashley#rgsr_in",false,getcharid(0));
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Hello. Okay, you're busy so that you don't know when someone died? So what happened? Don't you think its a big deal?";
			next;
			cutin "",255;
			mes "[ Staff ]";
			mes "Everyone, please come out.";
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "Hello, Med. I've been looking forward to meeting you again.";
			next;
			cutin "",255;
			mes "[ Med ]";
			mes "Ashley? Oh my, is it really you Ashley? Are you okay? What are you doing here? Are you go to question someone who's betrayed us and changed sides?";
			npctalk "I don't give up easily.","Lazy#rgsr_in",bc_self;
			unittalk getcharid(3),strcharinfo(0) + " : You're a natural.",bc_self;
			next;
			mes "[ Med ]";
			mes "Are you going to arrest these traitors, cruelly torture them, and make them reveal all their sins?";
			mes "This is like a spy novel!";
			npctalk "Oooh! Someone else here has a lot of imagination.","Lazy#rgsr_in",bc_self;
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "I didn't come for that. Have you seen a facility maintenance employee by the name of Patrick Kaufman? Where is he now?";
			next;
			cutin "",255;
			mes "[ Med ]";
			mes "Pa... who? Patrick Kaufman? Who is that? I don't know... oh! have you asked <NAVI>[Sammy]<INFO>rgsr_in,12,46,0,000,0</INFO></NAVI>?";
			mes "Sammy would know more. He manages the workforce here. You should go meet him.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Thank you for your help. Keep on rebuilding this lab.";
			next;
			cutin "",255;
			mes "[ Med ]";
			mes "And would you like to tell me who you are?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "These people don't even know the face of the Vice President they work for.";
			next;
			cutin "",255;
			mes "[ Med ]";
			mes "Ah!! That's you, I'm so sorry! I'll do my best!";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "We should go <NAVI>[here]<INFO>rgsr_in,12,46,0,000,0</INFO></NAVI> now~";
			ep_illusion = 24;
			completequest 17009;
			setquest 17010;
			close2;
			cutin "",255;
			cloaknpc("Lazy#rgsr_in",true,getcharid(0));
			cloaknpc("Kaya#rgsr_in",true,getcharid(0));
			cloaknpc("Ashley#rgsr_in",true,getcharid(0));
			questinfo_refresh();
			end;
			
		case 24:
			mes "[ Med ]";
			mes "If you want more information, you should ask <NAVI>[Sammy]<INFO>rgsr_in,12,46,0,000,0</INFO></NAVI> at the entrance.";
			end;
			
		default:
			mes "[ Staff ]";
			mes "This place is restricted from outsiders, please leave.";
			close;
	}
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 23");
	end;
}

rgsr_in,12,46,7	script	Staff#rgsr	4_M_04,{
	switch(ep_illusion){
		case 24:
			mes "[ Staff ]";
			mes "What are you doing here? You can't be here unless you have an apointment.";
			next;
			cloaknpc("Lazy#rgsr_in2",false,getcharid(0));
			cloaknpc("Kaya#rgsr_in2",false,getcharid(0));
			cloaknpc("Ashley#rgsr_in2",false,getcharid(0));
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "Hey, Sammy. Could I ask you a few questions?";
			next;
			cutin "",255;
			mes "[ Sammy ]";
			mes "Ashley? What are you doing here...?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Good afternoon. We want to ask you a few questions.";
			next;
			cutin "",255;
			mes "[ Sammy ]";
			mes "What do you want to ask me?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "This is the Vice President, here with us.";
			next;
			cutin "",255;
			mes "[ Sammy ]";
			mes "Vice President?";
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "Yes, this is the Vice President, Kaya Toss.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Nice to meet you, I'm Kaya Toss.";
			next;
			cutin "",255;
			mes "[ Sammy ]";
			mes "Oh my, Vice President. What are you doing in such a place... oh, what do you want to know?";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Oh wow, look at the attitude change. All we had to do was say the magic words : Vice President.";
			mes "That was too easy.";
			unittalk getcharid(3),strcharinfo(0) + " : It does look a little to easy.",bc_self;
			next;
			mes "[ Lazy ]";
			mes "I should probably use it more often from now on?";
			unittalk getcharid(3),strcharinfo(0) + " : Then you'll be caught Lazy.",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "I'd like to know where Patrick Kaufman is. He is a facility maintenance employee who was sent here.";
			next;
			cutin "",255;
			mes "[ Sammy ]";
			mes "Pa... Patrick Kaufman... Patrick... Well... Ah! I remember!";
			specialeffect EF_BLUELIGHTBODY,AREA,"Pat#rgsr_in";
			specialeffect EF_BLUELIGHTBODY,AREA,"Laboratory Staff#rgsr_in2";
			cloaknpc("Pat#rgsr_in",false,getcharid(0));
			cloaknpc("Laboratory Staff#rgsr_in2",false,getcharid(0));
			sleep2 2000;
			npctalk "You'll be joining a new laboratory next week. Don't get too lonely when you move away.","",bc_self;
			sleep2 2000;
			npctalk "Why? I like it here.","Pat#rgsr_in",bc_self;
			sleep2 2000;
			npctalk "Are you sick... or have any illness in particular","Laboratory Staff#rgsr_in2",bc_self;
			sleep2 2000;
			npctalk "No, my body is strong.","Pat#rgsr_in",bc_self;
			sleep2 2000;
			cloaknpc("Pat#rgsr_in",true,getcharid(0));
			cloaknpc("Laboratory Staff#rgsr_in2",true,getcharid(0));
			next;
			mes "[ Sammy ]";
			mes "... and then he was sent to another laboratory.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "You aren't supposed to relocate new employees for at least a whole year, why are you constantly asking for more workforce?";
			next;
			cutin "",255;
			mes "[ Sammy ]";
			mes "Yeah...? Why are we being sent so many? I have ^0000FFnever asked or more manpower in the building^000000. When new people arrive here, I assume they're simply a transfer.";
			next;
			cutin "",255;
			mes "[ Sammy ]";
			mes "So when Pat came here, I thought he was also a transfer. Especially at the time, because of the new research facility, the maintenance and logistic department teams...";
			mes "^0000FFwere transferring people a lot.^000000";
			npctalk "That's why I didn't know about it.","Ashley#rgsr_in2",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Where is the location of the transfer laboratory?";
			next;
			cutin "",255;
			mes "[ Sammy ]";
			mes "I don't know the exact location.";
			mes "It's somewhere at the ^0000FFEinbroch's outer zone.^000000 I've heard many new facilities involve dangerous experiments that can't be done in the city, so workforce is sent outside.";
			next;
			mes "[ Sammy ]";
			mes "But... maybe... was there another reason for the transfers? What...";
			mes "What happened to the people?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "A new laboratory... I couldn't investigate it. It's a new laboratory that needs a lot of people, but I wasn't able to find it. What do you think? Can you smell us getting closer?";
			unittalk getcharid(3),strcharinfo(0) + " : It's very surprising.",bc_self;
			npctalk "Right? It's also rude.","Lazy#rgsr_in2",bc_self;
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "This is certainly not in the papers I've received. There were only mentions of departures and few transfers. All the details were missing.";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "They wrote it like that on purpose,";
			mes "someone with enough suspicious would have figured out the truth.";
			next;
			mes "[ Lazy ]";
			mes "Perhaps someone didn't want you to learn the truth and deliberately removed those details. Otherwise it would have been shown in the original documents.";
			npctalk "They are so organized.","Lazy#rgsr_in2",bc_self;
			next;
			cutin "ep171_kaya02",0;
			mes "[ Kaya ]";
			mes "A new facility... I must find out where it is. There might be more things we don't know about.";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "You keep going on and on and on. If someone dies, I have to confirm it with my own eyes.";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "Let's get more information from the <NAVI>[Office]<INFO>lhz_in01,80,210,0,000,0</INFO></NAVI>.";
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Are you going to the Human Resources?";
			mes "I've already been there.";
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "How deeply did you investigate the Enterprise?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Oh no~ you still think I'm a liar.";
			mes "Where else will you find someone as trustworthy as I am?";
			next;
			select("What did you just say?");
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "One of the employee here said that one of my very distant relative passed away and left a big legacy.";
			mes "I wasn't able to reach him, and then I came here looking for what was left for me.";
			next;
			select("You believed him?");
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Why not? Does the adventurer have any relatives? I don't know...";
			mes "Romance and thrills, hehe. We've always waited for this dream to happen.";
			unittalk getcharid(3),strcharinfo(0) + " : Why look at people with such eyes.",bc_self;
			next;
			cutin "ep171_as01",1;
			mes "[ Ashley ]";
			mes "Oh...";
			unittalk getcharid(3),strcharinfo(0) + " : Your eyes are glowing!",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Does your guard know some romance?";
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "There's no time for this, let's go.";
			ep_illusion = 25;
			completequest 17010;
			setquest 17011;
			close2;
			cutin "",255;
			cloaknpc("Lazy#rgsr_in2",true,getcharid(0));
			cloaknpc("Kaya#rgsr_in2",true,getcharid(0));
			cloaknpc("Ashley#rgsr_in2",true,getcharid(0));
			end;
			
		case 25:
			mes "[ Sammy ]";
			mes "I didn't mean to cover up anything, it's just what I heard. Did everyone else went to the <NAVI>[Office]<INFO>lhz_in01,80,210,0,000,0</INFO></NAVI>?";
			end;
			
		default:
			mes "[ Staff ]";
			mes "What are you doing here? You can't be here unless you have an apointment.";
			close;
	}
	end;
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 24");
	end;
}

rgsr_in,157,84,5	duplicate(dummynpc)	Lazy#rgsr_in	4_M_LAZY
rgsr_in,158,87,5	duplicate(dummynpc)	Kaya#rgsr_in	4_EP17_KAYA
rgsr_in,157,88,5	duplicate(dummynpc)	Ashley#rgsr_in	4_EP17_AS
rgsr_in,16,49,3	duplicate(dummynpc)	Lazy#rgsr_in2	4_M_LAZY
rgsr_in,17,48,3	duplicate(dummynpc)	Kaya#rgsr_in2	4_EP17_KAYA
rgsr_in,18,47,3	duplicate(dummynpc)	Ashley#rgsr_in2	4_EP17_AS
rgsr_in,15,46,1	duplicate(dummynpc)	Pat#rgsr_in	4_M_REPAIR
rgsr_in,13,49,5	duplicate(dummynpc)	Laboratory Staff#rgsr_in2	4_M_SCIENCE

//= Rudus
sp_rudus,184,360,3	script	Elena Bolkova#171_rudus	4_F_ELENA,{
	switch(ep_illusion){
		case 3:
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "Oh, this place is so peaceful.";
			mes "You look pale.";
			mes "...";
			mes "It's a joke, I think I need more time to properly investigate this area.";
			next;
			select("Any Problem?");
			mes "[ Elena Bolkova ]";
			mes "They said barriers were built because the factory closed.";
			mes "Something doesn't feel right here, though.";
			next;
			mes "[ Elena Bolkova ]";
			mes "Anyway, I should go beyond the barrier to get satisfying information for Tess?";
			mes "My crew is working on securing the doorway first. If you open it, go check out the other side.";
			next;
			mes "[ Elena Bolkova ]";
			mes "You remember Lucky? I brought him along, so go ahead and ask him about the progress.";
			ep_illusion = 4;
			completequest 7851;
			setquest 7852;
			close3;
			
		case 4:
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "I need to find out what's beyond the barrier.";
			mes "If there's nothing there, I'll withdraw. But if there's nothing at all, I'll go at it with full force.";
			mes "What do you think?";
			close3;
			
		case 5:
			npctalk "Elena : Ehehehe. Whatever this place is, it'll be a challenge.","",bc_self;
			end;
			
		case 6:
			if(checkquest(7858,HUNTING) != 2){
				cutin "162elena_01",2;
				mes "[ Elena Bolkova ]";
				mes "Do you want to investigate beyond the barrier?";
				mes "If something suspicious comes up, I'll take care of it!";
				close3;
			}
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "So now it's Elena Bolkova's turn!";
			mes "Adventurer, you go to Cat on Bullet and tell Tess what happenede here.";
			next;
			mes "[ Elena Bolkova ]";
			mes "There is no difference whether you report it or someone else does.";
			mes "This is just a dump.";
			completequest 7858;
			setquest 7859;
			ep_illusion = 7;
			getitem 25723,15;
			getexp 800000,800000;
			close3;
			
		case 7:
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "The USU will manage somehow, you go ahead and report back to Tess about the situation.";
			mes "In the meantime, I have to help out my team.";
			close3;
			
		default:
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "This area is a dispocal facility.";
			mes "It's where they throw away their failed experiments.";
			next;
			cutin "162elena_02",2;
			mes "[ Elena Bolkova ]";
			mes "It would be great if those guys went outside the barrier.";
			mes "I haven't trained today!";
			close3;		
	}
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 3");
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 6 && checkquest(7858,HUNTING) == 2");
end;
}

function	script	illusion_barrier_check	{
	setarray .@quest,7854,7855,7856;
	for(.@i = 0; .@i < 3; .@i++){
		if(isbegin_quest(.@quest[.@i]) == 1)
			.@q++;
	}
	if(.@q == 3){
		for(.@i = 0; .@i < 3; .@i++)
			completequest .@quest[.@i];
		setquest 7857;
		questinfo_refresh;
	}
	return;
}

sp_rudus,193,284,0	script	Rookie#171_rudus	4_M_ROOKIE,{
	switch(ep_illusion){
		case 4:
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "Are you an adventurer?";
			mes "Did Tess send you? If you want more information, you'll have to find it yourself.";
			next;
			mes "[ Rookie ]";
			mes "Would you look at this place?";
			mes "It's a triple-edged door. I'm having a hard time opening it up.";
			next;
			mes "[ Rookie ]";
			mes "Of course, if you use magic like Teleport or Fly Wings, you can get past it.";
			mes "We have a lot of people with us though... *laughs*";
			mes "Wouldn't you prefer to go in directly with your own two legs?";
			next;
			mes "[ Rookie ]";
			mes "Other rebellion members are already looking for an entry point. If you don't mind, look for them adventurer.";
			mes "Maybe you'll find something out.";
			completequest 7852;
			setquest 7853;
			ep_illusion = 5;
			next;
			mes "[ Rookie ]";
			mes "The abandoned mine is beyond this barrier. Be careful.";
			close3;
			
		case 5:
			if(!isbegin_quest(7857)){
				cutin "16loo_01",2;
				mes "[ Rookie ]";
				mes "Other rebellion members are already looking for an entry point. If you don't mind, look for them adventurer.";
				mes "Maybe you'll find something out.";
				next;
				mes "[ Rookie ]";
				mes "The abandoned mine is beyond this barrier. Be careful.";
				close3;
			}
			cutin "16loo_03",2;
			mes "[ Rookie ]";
			mes "Hey... So you found a watchtower and Small Hole?";
			mes "A Small Hole so small a human couldn't have made it? Ahah...";
			mes "That's too bad.";
			next;
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "If I could use that Small Hole, my efforts would be in vain wouldn't they?";
			mes "Don't be disappointed!";
			mes "I finally unlocked this door.";
			next;
			mes "[ Rookie ]";
			mes "This button right here opens the door, but the moment you release it, the door closes.";
			mes "Does that mean there's no way for a single person to cross on the other side?";
			next;
			mes "[ Rookie ]";
			mes "Even if you come with 2 people...";
			mes "This is awkward.";
			mes "It seems to have been made with the intention of 'throwing in'.";
			next;
			select("Throwing in?");
			mes "[ Rookie ]";
			mes "There is a place like this with similar devices.";
			mes "A prison. A jail. It's for prisoners... What is this place?!";
			mes "What is it? Are we in a criminal camp?";
			next;
			mes "[ Rookie ]";
			mes "No that's not it. If it was such a facility, Tess wouldn't have known about it.";
			mes "Well, for now, you should just go in.";
			next;
			select("I hear suspicious sounds...");
			mes "[ Rookie ]";
			mes "Well? Aaah! I heard that. These are strange screams? So the other members went in.";
			mes "I'll stay here to manage the switch while you go on the other side.";
			next;
			mes "[ Rookie ]";
			mes "Are you going to join the others too?";
			mes "If you find the sources of the noises, see monsters, or anything else out of ordinary, please let me know!";
			completequest 7857;
			setquest 7858;
			ep_illusion = 6;
			next;
			cutin "16loo_02",2;
			mes "[ Rookie ]";
			mes "When you want to come out, do 'tock-tock-tock' on the other side and knock on the iron door three times.";
			mes "I'll open the door from my end.";
			mes "Of course you can also use magic to get out... Ahaha.";
			close3;
			
		case 6:
			if(checkquest(7858,HUNTING) != 2){
				cutin "16loo_01",2;
				mes "[ Rookie ]";
				mes "Other rebellion members have already entered.";
				mes "We're not going to abandon them.";
				mes "Be careful.";
				close3;
			}
			mes "[ Rookie ]";
			mes "Woah... what the hell happened in there?";
			mes "You look exhausted...";
			next;
			select("The monsters came out.");
			mes "[ Rookie ]";
			mes "The monsters!?";
			mes "Let's report to Elena! Then go to Can on Bullet and report back to Tess!";
			next;
			mes "[ Rookie ]";
			mes "Can the monsters get out from the small gap?";
			mes "I'll stay here and return with Elena in a bit!";
			close3;

		default:
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "It's nice to suddenly have so much work to do... But I won't be able to to do everything on own...";
			close3;			
	}
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 4");
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 5 && checkquest(7857) == 1");
end;
}

sp_rudus,122,286,3	script	Rebellion Crew#171_rudus01	4_M_REBELLION3,{
	if(ep_illusion == 5){
		if(!isbegin_quest(7855)){
			mes "[ Rebellion Crew ]";
			mes "Well? What is the adventurer doing here?";
			mes "Are you part of the operation too?";
			next;
			mes "[ Rebellion Crew ]";
			mes "Oh! I'll let you know what I found here.";
			mes "Do you see this big column?";
			mes "I went on top of it, the watchtower!";
			next;
			mes "[ Rebellion Crew ]";
			mes "It looks better than the barrier.";
			mes "I don't know why there's a watchtower in smelting facility, but it's definitely a watchtower!";
			mes "This is the discovery of the century. Ahaha!";
			next;
			mes "[ Rebellion Crew ]";
			mes "When I was looking up there, I think I saw something move.";
			mes "I'm going to make sure of what I saw by going back up!";
			setquest 7855;
			illusion_barrier_check;
			end;
		}
		mes "[ Rebellion Crew ]";
		mes "I will learn everything I can about the watchtower! You can report back to Lucky!";
		close;
	}
	npctalk "I'm going to have to take over this watchtower too...!","",bc_self;
	end;
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 5 && checkquest(7855) == -1");
end;
}

sp_rudus,304,266,3	script	Rebellion Crew#171_rudus02	4_M_REBELLION3,{
	if(ep_illusion == 5){
		if(!isbegin_quest(7854)){
			mes "[ Rebellion Crew ]";
			mes "Well? Are you involved with the operation?";
			mes "Even though I live in Einbroch,";
			mes "This is the first time I've seen it.";
			next;
			select("What's wrong?");
			mes "[ Rebellion Crew ]";
			mes "Look over here, is it not strange?";
			mes "It's a railway to carry minerals, but they've built a barrier on top.";
			mes "It doesn't even have a door.";
			next;
			mes "[ Rebellion Crew ]";
			mes "At first I thought this wall was meant to separate the smelting factory and the mine...";
			mes "But I don't think it is?";
			next;
			select("Was the barrier created afterwards?");
			mes "[ Rebellion Crew ]";
			mes "For sure.";
			mes "But why do you need a barrier to an already closed mine and factory?";
			mes "And this type of structure is what's used in prisons.";
			next;
			mes "[ Rebellion Crew ]";
			mes "I don't know the purpose of this wall, but it was not built while the factory was still running.";
			next;
			mes "[ Rebellion Crew ]";
			mes "I'll have a closer look and join you later.";
			mes "Please tell Lucky.";
			setquest 7854;
			illusion_barrier_check;
			end;
		}
		mes "[ Rebellion Crew ]";
		mes "I have to look a bit more.";
		end;
	}
	npctalk "Uh... I'm going crazy with all these strange noises.","",bc_self;
	end;
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 5 && checkquest(7854) == -1");
end;
}

sp_rudus,27,300,0	script	Small Hole#171_rudus	4_ENERGY_BLUE,{
	if(ep_illusion == 5){
		if(!isbegin_quest(7856)){
			mes "There is a small enough hole for a child to go through.";
			mes "It seems like an animal has dug a hole and made a little cave.";
			mes "Let's have another look around.";
			setquest 7856;
			illusion_barrier_check;
			end;
		}
		unittalk getcharid(3),strcharinfo(0) + " : I'll be back.";
		end;
	}
	unittalk getcharid(3),strcharinfo(0) + " : This hole is too small to be useful.",bc_self;
	end;
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 5 && checkquest(7856) == -1");
end;
}

sp_rudus,130,200,4	script	Morning#171_quest	4_EP17_MORNING,{
	if(ep_illusion < 3) end;
	if(checkquest(5856) < 0){
		cutin "ep171_morning03",2;
		sleep2 2000;
		unittalk getcharid(3),strcharinfo(0) + " : The child is laughing with a bright smile that doesn't match this place.",bc_self;
		end;
	}
	switch(checkquest(5861,PLAYTIME)){
		case -1:
			break;
			
		case 0: case 1:
			cutin "ep171_morning03",2;
			unittalk getcharid(3),strcharinfo(0) + " : Morning is smiling today.",bc_self;
			select("Chat with Morning.");
			cutin "ep171_morning03",1;
			switch(rand(1,5)){
				case 1:
					unittalk getcharid(3),strcharinfo(0) + " : Morning, what do you eat for breakfast?",bc_self;
					sleep2 2000;
					npctalk "Morning : I think about the story you told me. I'm sorry to hear that.","",bc_self;
					sleep2 2000;
					break;
					
				case 2:
					unittalk getcharid(3),strcharinfo(0) + " : Morning, have you been to other floors inside Rudus?",bc_self;
					sleep2 2000;
					npctalk "Morning : The adventurer said the other floors were scary. Mushroom...","",bc_self;
					sleep2 2000;
					break;
					
				case 3:
					unittalk getcharid(3),strcharinfo(0) + " : Morning, why are you called morning?",bc_self;
					sleep2 2000;
					npctalk "Morning : Morning? It's morning here.","",bc_self;
					sleep2 2000;
					break;
					
				case 4:
					unittalk getcharid(3),strcharinfo(0) + " : Morning, kurururu!",bc_self;
					sleep2 2000;
					npctalk "Morning : .......?","",bc_self;
					emotion ET_QUESTION;
					sleep2 2000;
					break;
					
				case 5:
					unittalk getcharid(3),strcharinfo(0) + " : Morning, why do you stay in Rudus?",bc_self;
					sleep2 2000;
					npctalk "Morning : Everyone is quiet, except you adventurer.","",bc_self;
					emotion ET_OHNO;
					sleep2 2000;
					break;
			}
			unittalk getcharid(3),strcharinfo(0) + " : It sounded like you're having a conversation with someone?",bc_self;
			cutin "",255;
			end;
			
		case 2:
			erasequest 5861;
			break;
	}
	for(.@i = 0; .@i < getarraysize(.quest_data$); .@i++){
		explode(.@temp$,.quest_data$[.@i],":");
		if(checkquest(atoi(.@temp$[0])) > 0){
			if(countitem(atoi(.@temp$[1])) < 10){
				.@UF = 1;
				break;
			} else {
				setpcblock PCBLOCK_ALL,true;
				unittalk getcharid(3),strcharinfo(0) + " : Ah, Morning! Would you mind?",bc_self;
				sleep2 2000;
				cutin "ep171_morning03",2;
				npctalk "Woah! I will enjoy this food. Thank you adventurer.","",bc_self;
				sleep2 2000;
				npctalk "First...","",bc_self;
				sleep2 2000;
				npctalk "This is what's left. I'll give it to you adventurer.","",bc_self;
				setquest 5861;
				erasequest atoi(.@temp$[0]);
				if(checkquest(5856) == 1){
					completequest 5856;
				}
				delitem atoi(.@temp$[1]),10;
				getitem 25669,5; //= Unknown Part
				getitem 25723,1; //= Cor Core
				getexp 750000,750000;
				setpcblock PCBLOCK_ALL,false;
				end;
			}
		}
		continue;
	}
	cutin "ep171_morning01",2;
	setpcblock PCBLOCK_ALL,true;
	unittalk getcharid(3),strcharinfo(0) + " : This kid seems to be Morning.",bc_self;
	if(select("Find a meal for Morning.:Chat with Morning.") == 2){
		setpcblock PCBLOCK_ALL,true;
		cutin "ep171_morning02",2;
		unittalk getcharid(3),strcharinfo(0) + " : Does morning have a hungry appetite?",bc_self;
		sleep2 2000;
		cutin "",255;
		unittalk getcharid(3),strcharinfo(0) + " : It doesn't seem he's willing to communicate.",bc_self;
		setpcblock PCBLOCK_ALL,false;
		end;
	}
	if(.@UF){
		npctalk "Is the adventurer back already?","",bc_self;
		setpcblock PCBLOCK_ALL,false;
		end;
	}
	unittalk getcharid(3),strcharinfo(0) + " : Ah, Morning! Would you mind? What do you want to eat today?",bc_self;
	.@index = rand(getarraysize(.quest_data$));
	explode(.@temp$,.quest_data$[.@index],":");
	sleep2 2000;
	npctalk .@temp$[2] +"! Morning wants " + getitemname(atoi(.@temp$[1])) + " for breakfast.","",bc_self;
	sleep2 2000;
	unittalk getcharid(3),strcharinfo(0) + " : Right! Is this what Morning wants?!",bc_self;
	emotion ET_HUK,getcharid(3);
	sleep2 2000;
	unittalk getcharid(3),strcharinfo(0) + " : You want " + getitemname(atoi(.@temp$[1])) + "? Would 10 be enough?",bc_self;
	emotion ET_STARE,getcharid(3);
	sleep2 2000;
	if(select("I'll bring it.:Something urgent happened.") == 2){
		cutin "",255; 
		setpcblock PCBLOCK_ALL,false;
		end;
	}
	cutin "ep171_morning02",2;
	if(checkquest(atoi(.@temp$[0])) > 0) //= Anti-Bug Check
		erasequest atoi(.@temp$[0]);
	setquest atoi(.@temp$[0]);
	npctalk "Wow~ Everyone! " + ((Sex == 1)?"Papa!":"Mama!"),"",bc_self;
	unittalk getcharid(3),strcharinfo(0) + " : Morning, wait a little and I'll be back.",bc_self;
	setpcblock PCBLOCK_ALL,false;
	cutin "",255;
	end;		

OnInit:
	setarray .quest_data$,"5862:909:Jellopies","5863:902:Roots","5864:940:Legs","5865:705:Clovers","5866:916:Feathers","5867:1016:Tails","5868:937:Canines","5869:942:Tails","5870:913:Tooth","5871:948:Footskins";
	questinfo(QTYPE_DAILYQUEST,QMARK_YELLOW,"checkquest(5856) == 2 && checkquest(5861,PLAYTIME) == -1");
	questinfo(QTYPE_DAILYQUEST,QMARK_YELLOW,"checkquest(5856) == 2 && checkquest(5861,PLAYTIME) == 2");
end;
}

sp_rudus,124,195,0	script	#morning_garbage_pile	4_ENERGY_WHITE,{
	if(checkquest(5856) == -1){
		mes "";
		mes "A lot of garbage is piled up around this rock. It seems to have been there for a while too. Let's dig the ground.";
		next;
		if(select("Dig.:Quit.") == 2) end;
		mes "";
		mes "I searched the ground and found a note someone buried.";
		setquest 5856;
		questinfo_refresh();
		end;
	}
	mes "";
	mes "A lot of garbage is piled up around this rock. It seems to have been there for a while too. Let's dig the ground.";
	next;
	if(select("Dig.:Quit.") == 2) end;
	mes "";
	mes "Someone seems to have already been through this.";
	close;
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"checkquest(5856) == -1");
	end;
}


sp_rudus,227,351,0	script	Suspicious Evidence#171_rudus	4_ENERGY_BLACK,{
	switch(finding_patrick){
		case 5:
			mes "[ "+strcharinfo(0)+" ]";
			mes "How do you find anything in such a big place? There is no one to ask.";
			mes "Can you really look at the traces of abandoned projects...?";
			next;
			mes "......";
			next;
			mes "............";
			next;
			mes "....................";
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "There's nothing here. I don't know what to look for...";
			next;
			mes "[ Suspicious Voices ]";
			mes "The ratio of mixture is 1:3... what are you doing?, it should be 1:4. Do you want the lab to explode?";
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "What.... I can hear <NAVI>[voices]<INFO>sp_rudus,15,280,0,101,0</INFO></NAVI>, where does it come from?";
			finding_patrick = 6;
			completequest 17024;
			setquest 17025;
			questinfo_refresh();
			end;
			
		case 6:
			mes "[ "+strcharinfo(0)+" ]";
			mes "What.... I can hear <NAVI>[voices]<INFO>sp_rudus,15,280,0,101,0</INFO></NAVI>, where does it come from?";
			end;
	}
	mes "[ "+strcharinfo(0)+" ]";
	mes "There is nothing here.";
	end;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"finding_patrick == 5";
end;	
}

sp_rudus,15,280,5	script	#171_EV_RUDUS	HIDDEN_WARP_NPC,12,12,{
	end;
	
OnTouch:
	if(finding_patrick == 6)
		cloaknpc("Discarded Person#171_Q_0",false,getcharid(0));
end;
}

sp_rudus,15,280,5	script	Discarded Person#171_Q_0	4_F_MUT1,{
	if(finding_patrick == 6){
		mes "[ Discarded Person ]";
		mes "A 1:2 ratio might better... No it's better not to experiment. I think you're right.";
		next;
		select("Oh, woah, hello?? It's ok I don't mind!");
		mes "[ Discarded Person ]";
		mes "Why are you surprised? I'm not dead yet.";
		unittalk getcharid(3),strcharinfo(0) + " : I'm sorry.",bc_self;
		next;
		mes "[ Discarded Person ]";
		mes "It's okay. I'd be surprised too if I saw myself. I try not to look in the mirrors.";
		npctalk "There are no mirrors here.","",bc_self;
		next;
		select("Why do you look like a researcher...?");
		mes "[ Discarded Person ]";
		mes "Why shouldn't a researcher be here?";
		mes "You want to know why a person who led experiments was thrown out in a dumpster and abandoned.";
		next;
		mes "[ Discarded Person ]";
		mes "My only goal is being succesful, and I've done all sort of things.";
		mes "That's a proper ending for me don't you think?";
		next;
		mes "[ Discarded Person ]";
		mes "Research and experimentation are not always safe. I thought I would be okay, but I couldn't avoid it in the end.";
		npctalk "I thought I would be okay.","",bc_self;
		next;
		mes "[ Discarded Person ]";
		mes "The person who abandoned me here didn't think I'd still be alive.";
		mes "Because the lab was crushed, toxic substances sprung up all over the place.";
		next;
		mes "[ Discarded Person ]";
		mes "Eheh. So I'm just going to wait here and die like this. I wanted to surprise the would with my research, but I ended up living here instead.";
		next;
		select("Are there any other people here?");
		mes "[ Discarded Person ]";
		mes "Why are you looking for? A dead person? A living person? Or perhaps a half dead person?";
		next;
		mes "[ Discarded Person ]";
		mes "How many discarded people do you think you'll find here?";
		npctalk "Since when do you think this site was used as a waste disposal facility?","",bc_self;
		next;
		mes "[ Discarded Person ]";
		mes "If they had a ^0000FFcertain physical condition and a poor background^000000, sometimes just homeless, it was easier to experiment on them.";
		next;
		mes "[ Discarded Person ]";
		mes "Don't look at me like that. The porrer you are, the better off your family is, we would be fools to not take advantage of these people. At least that's what I thought back then.";
		next;
		mes "[ Discarded Person ]";
		mes "Where do you think all these missing people have gone to over the years?";
		next;
		mes "[ Discarded Person ]";
		mes "Many of the missing people of Schwarzwald would end up here. Are you going to investigate every single one of them? If you had enough time, it wouldn't be a bad thing.";
		next;
		mes "[ Discarded Person ]";
		mes "Or are you only looking for one person in particular?";
		next;
		select("I'm looking for Patrick Kaufman.");
		mes "[ Discarded Person ]";
		mes "When did he come in?";
		next;
		select("I don't know that.");
		mes "[ Discarded Person ]";
		mes "Well.. I ^0000FFdon't have the information you seek.^000000 I was the last person to come here.";
		next;
		mes "[ Discarded Person ]";
		mes "I don't have much to do, but I've looked through this place and I haven't seen anyone by that that... you know what I mean?";
		next;
		mes "[ Discarded Person ]";
		mes "You should try and look for an ^0000FFIdentification Bracelet^000000 in the pile of garbage. DO you know what it is?";
		mes "The wrist band is a bracelet. The names of the specimens are written on it.";
		next;
		mes "[ Discarded Person ]";
		mes "If he did, there would be a braclet somewhere on the floor. It might not even be there anymore...";
		next;
		mes "[ Discarded Person ]";
		mes "If you can't find him, you can probably just buy a bracelet at a market and have a proper burial instead.";
		next;
		select("....");
		mes "[ Discarded Person ]";
		mes "... why am I not going? I did everything I wanted to do here.";
		next;
		select("We're going out together.");
		mes "[ Discarded Person ]";
		mes "Leaving this place? Don't, I'm dying. It's the gruesome truth. I know my body well. It's what I studied.";
		next;
		mes "[ Discarded Person ]";
		mes "For now, my foot is like this, but the other leg will change soon.","Then both of my arms... and at the end... can you still call me humans?";
		next;
		mes "[ Discarded Person ]";
		mes "Even if I received treatments, there's no chance I'd survive. I know this well. Wouldn't it be best for me to have a quiet life here without anyone?";
		next;
		mes "[ Discarded Person ]";
		mes "See, this is my family nmow. Why do I have to carry such a heavy load? It's a hundred times easier to give up hope than to be alive elsewhere isn't it?";
		next;
		mes "[ Discarded Person ]";
		mes "Do I sound weird when I say stuff like that? I think I'm losing it a little.";
		next;
		mes "[ Discarded Person ]";
		mes "Yes, sometimes I even dream of taking people out of their misery.";
		next;
		mes "[ Discarded Person ]";
		mes "It's not probably what their family would have wanted, but it's dangerous outside for them. You know what I mean?";
		next;
		mes "[ Discarded Person ]";
		mes "And... I don't think it's a coincidence.";
		npctalk "I don't believe in higher power, but maybe I'm starting to.","",bc_self;
		next;
		mes "[ Discarded Person ]";
		mes "If you come back here after a while and I'm completely turned into a monster, please kill me.";
		next;
		mes "[ Discarded Person ]";
		mes "I would have rather have my life cut off short than living just a second as a monster. Got it?";
		next;
		mes "[ Discarded Person ]";
		mes "Huh. I've told you a lot today, I should rest.";
		getexp 300000,300000;
		finding_patrick = 7;
		completequest 17025;
		setquest 17026;
		questinfo_refresh();
		end;
	}
	mes "[ Discarded Person ]";
	mes "You should try and look for an ^0000FFIdentification Bracelet^000000 in the pile of garbage. DO you know what it is?";
	mes "The wrist band is a bracelet. The names of the specimens are written on it.";
	end;
					
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"finding_patrick == 6";
	cloaknpc(strnpcinfo(0),true);
end;	
}

sp_rudus,236,46,0	script	Suspicious Evidence#ep171_0	4_ENERGY_BLACK,{
	if(finding_patrick != 7){
		mes "[ "+strcharinfo(0)+" ]";
		mes "This seems like a dead end.";
		end;
	}
	.@rand = rand(1,5);
	.@index = atoi(replacestr(strnpcinfo(2),"ep171_",""));
	.@var = getd("171_evidence_" + .@index);
	if(.@var){
		mes "[ "+strcharinfo(0)+" ]";
		mes "I've already seen this place. Let's look elsewhere.";
		end;
	}
	if(.@rand == 1 || checkquest(17031) == 1){
		mes "[ "+strcharinfo(0)+" ]";
		mes "I digged a bracelet buried in a pile of garbage. This seems to be an identification bracelet from the experiments. It says... Pat... Patrick... Kauf...man.";
		next;
		mes "[ "+strcharinfo(0)+" ]";
		mes "This is Patrick Kaufman's bracelet... let's go back to <NAVI>[Kaya]<INFO>sp_cor,136,146,0,000,0</INFO></NAVI>.";
		finding_patrick = 8;
		completequest 17031;
		setquest 17032;
		getitem 25666,1;
		for(.@i = 0; .@i < 5; .@i++)
			setd("171_evidence_" + .@i,0);
		end;
	}
	mes "[ "+strcharinfo(0)+" ]";
	mes "I looked throught the garbage and found several identification bracelet. Let's look elsewhere.";
	for(.@i = 17026; .@i < 17031; .@i++){
		if(isbegin_quest(.@i)){
			erasequest .@i;
			setquest .@i+1;
			setd("171_evidence_" + .@index,1);
		}
	}
	end;
	
OnInit:
	.@index = atoi(replacestr(strnpcinfo(2),"ep171_",""));
	questinfo QTYPE_QUEST,QMARK_YELLOW,"finding_patrick == 7 && 171_evidence_" + .@index + " == 0";
end;
}

sp_rudus,55,137,0	duplicate(Suspicious Evidence#ep171_0)	Suspicious Evidence#ep171_1	4_ENERGY_BLACK
sp_rudus,332,235,0	duplicate(Suspicious Evidence#ep171_0)	Suspicious Evidence#ep171_2	4_ENERGY_BLACK
sp_rudus,364,134,0	duplicate(Suspicious Evidence#ep171_0)	Suspicious Evidence#ep171_3	4_ENERGY_BLACK
sp_rudus,221,165,0	duplicate(Suspicious Evidence#ep171_0)	Suspicious Evidence#ep171_4	4_ENERGY_BLACK

//= SP OS
sp_os,252,359,5	script	Dien#sp_os	4_F_DIENE,{
	if(ep_illusion == 34){
		cutin "ep162_dn01",2;
		mes "[ Dien ]";
		mes "Oh!";
		mes "Are you back already?";
		mes "Did you find it?";
		next;
		select("Hand over the picture");
		cutin "ep171_trio_memory",1;
		mes "[ Dien ]";
		mes "Thank you.";
		mes "You may think it's not worth much, but it means a lot to me...";
		delitem 25665,1;
		next;
		cutin "ep162_dn01",2;
		mes "[ Dien ]";
		mes "What's with that expression...?";
		next;
		cutin "ep162_rds03",2;
		mes "[ Ridsh ]";
		mes "I've never seen that in the room.";
		next;
		cutin "ep162_dn01",2;
		mes "[ Dien ]";
		mes "Ahah...";
		mes "It's a souvenir of us when we were children.";
		mes "Was it always like that?";
		next;
		cutin "ep162_rds03",2;
		mes "[ Ridsh ]";
		mes "Were we really so loud?";
		mes "Anyway, we've opened the door, let's go.";
		mes "I think people are coming.";
		ep_illusion = 35;
		completequest 11603;
		getexp 200000,100000;
		close2;
		cutin "",255;
		warp "sp_cor",163,60;
		end;
	}
	mes "[ Dien ]";
	mes "It's been a while since I've been so excited.";
	end;
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 34");
end;
}

//= Cor OS
function	script	171_worker_talk	{
.@type = getarg(0);
.@npc$ = getarg(1);
	switch(.@type){
		case 1: .@talk$ = "Oh wow! We weren't lucky this morning!"; break;
		case 2: .@talk$ = "Who's being so loud?"; break;
		case 3: .@talk$ = "It looks like it's these guys."; break;
		case 4: .@talk$ = "It's a mess!"; break;
		case 5: .@talk$ = "You didn't? Then please get out!"; break;
		case 6: .@talk$ = "Why are messing with someone else's home?"; break;
		case 7: .@talk$ = "Are you bringing more?"; break;
		case 8: .@talk$ = "I can't get in here anymore!"; break;
		case 9: .@talk$ = "I can see your eyes!"; break;
		case 10: .@talk$ = "No, please leave. We can't do this."; break;
		case 11: .@talk$ = "No, did you guys kill everyone?"; break;
		case 12: .@talk$ = "We don't know who you are."; break;
		case 13: .@talk$ = "Stay still everyone, let me see what they want."; break;
		case 14: .@talk$ = "I don't see that?"; break;
		case 15: .@talk$ = "Yeah, that's right. I haven't been able to go anywhere."; break;
		case 16: .@talk$ = "No, that's not what we do!"; break;
		case 17: .@talk$ = "Are we doing chores too now?"; break;
		case 18: .@talk$ = "Well that's just awesome!"; break;
		case 19: .@talk$ = "Who do you think you are?"; break;
		case 20: .@talk$ = "Yeah, just look at you guys."; break;
		case 21: .@talk$ = "My neighbor always used to play with a gun, it was scary!"; break;
		case 22: .@talk$ = "You'd like that? Wouldn't you?"; break;
		case 23: .@talk$ = "Why should we put up with that?"; break;
		case 24: .@talk$ = "It's okay. There is no need to make a fuss!"; break;
		case 25: .@talk$ = "I'm just doing my work! What are you planning to do?"; break;
		case 26: .@talk$ = "What are they saying now?"; break;
		case 27: .@talk$ = "Yeah. What are they talking about?"; break;
		case 28: .@talk$ = "How did we know there were researchers?"; break;
		case 29: .@talk$ = "Wait, where have you been?"; break;
		case 30: .@talk$ = "They will come when the rice is cooked."; break;
		case 31: .@talk$ = "Is anyone allowed to leave? I heard you!"; break;
		case 32: .@talk$ = "What, are we rubbish to you? Is that it?"; break;
		case 33: .@talk$ = "Yeah! without us, the lab can't function!"; break;
		case 34: .@talk$ = "We won't listen to you anymore! Get out!"; break;
		case 35: .@talk$ = "Come on! Get out!"; break;
		case 36: .@talk$ = "Your existence itself is a threat to us!"; break;
		case 37: .@talk$ = "Come on, I'll fight you at the end of the day!"; break;
		case 38: .@talk$ = "Do you think you can just stay here?"; break;
		case 39: .@talk$ = "Just come and try! Do it!!"; break;
		case 40: .@talk$ = "Who's that?"; break;
		case 41: .@talk$ = "Are you on the meeting square, who is this now?"; break;
		case 42: .@talk$ = "Wait, I think I just heard something? Vice President?"; break;
		case 43: .@talk$ = "We have nothing else to say!"; break;
		case 44: .@talk$ = "If that's the Vice President, then I'm the Vice President too!"; break;
		case 45: .@talk$ = "No, what? For Real?"; break;
		case 46: .@talk$ = "Well, me neither."; break;
		case 47: .@talk$ = "What are you doing here?"; break;
		case 48: .@talk$ = "Yeah, why are you here?"; break;
		case 49: .@talk$ = "What are you trying to say now?"; break;
		case 50: .@talk$ = "That's right, why?"; break;
		case 51: .@talk$ = "I don't know..."; break;
		case 52: .@talk$ = "Do we just suddenly introduce ourselves?"; break;
		case 53: .@talk$ = "Oh, I don't think that's it."; break;
		case 54: .@talk$ = "They were doing that with sunlight right?"; break;
		case 55: .@talk$ = "Right. I saw it."; break;
		case 56: .@talk$ = "Eh, did you do something illegal?"; break;
		case 57: .@talk$ = "So you think we've done illegal experiments?"; break;
		case 58: .@talk$ = "it's you guys who're doing something illegal!"; break;
		case 59: .@talk$ = "I thought you were the Vice President."; break;
		case 60: .@talk$ = "Is he a fraud?"; break;
		case 61: .@talk$ = "Why would you say that to your own workers?"; break;
		case 62: .@talk$ = "I toldyou, he looks like an impostor."; break;
		case 63: .@talk$ = "That's defnitely strange, isn't it?"; break;
		case 64: .@talk$ = "That's right! Why aren't there a dozen bureaucrats with him?"; break;
		case 65: .@talk$ = "I don't think he is."; break;
		case 66: .@talk$ = "That's true."; break;
		case 67: .@talk$ = "Someone else might look better?"; break;
		case 68: .@talk$ = "Do we look like an idiots to you? Are you going to use us?"; break;
		case 69: .@talk$ = "Take your time."; break;
		case 70: .@talk$ = "Oh, look at that! Now the president is here~"; break;	
		case 71: .@talk$ = "He's not the president, he's from the office of the president."; break;
		case 72: .@talk$ = "What? Is what I'm hearing true?"; break;
		case 73: .@talk$ = "That's right, I heard that too."; break;
		case 74: .@talk$ = "Why are we branded as criminals, we're hard workers!"; break;
		case 75: .@talk$ = "Yeah! Can't you see our hardworking hands?"; break;
		case 76: .@talk$ = "We have to deal with these sinners as well!"; break;
		case 77: .@talk$ = "I know, I wouldn't want to be here either."; break;
		case 78: .@talk$ = "We're those who work!"; break;
		case 79: .@talk$ = "I've been moving things all day long"; break;
		case 80: .@talk$ = "Doesn't it seem quiet?"; break;
		case 81: .@talk$ = "So just go back."; break;
		case 82: .@talk$ = "Use force, as in kill us?"; break;
		case 83: .@talk$ = "We've been handling ourselves just fine from the start!"; break;
		case 84: .@talk$ = "Are you listening to yourselves?"; break;
		case 85: .@talk$ = "Hey, don't move!"; break;
		case 86: .@talk$ = "Well, now it's a big deal."; break;
		case 87: .@talk$ = "The senior researcher is here."; break;
		case 88: .@talk$ = "Did our researcher always had such a personality?"; break;
		case 89: .@talk$ = "Well, I never had a word with her, did you?"; break;
		case 90: .@talk$ = "What's the matter?"; break;	
		case 91: .@talk$ = "Oh!!! What is all this!"; break;
		case 92: .@talk$ = "Please, you're not alone!"; break;
		case 93: .@talk$ = "Aaaaah!! Researcher!! It's us! We're here too!"; break;
		case 94: .@talk$ = "El, Elyumina! Wait a second!"; break;
		case 95: .@talk$ = "The researcher is crazy!"; break;
		case 96: .@talk$ = "She is!!"; break;
		case 97: .@talk$ = "Hey!! Are you okay?!"; break;
		case 98: .@talk$ = "What is that sound!!"; break;
		case 99: .@talk$ = "Aaah!!"; break;
		case 100: .@talk$ = "No! Please!!"; break;	
		case 101: .@talk$ = "The researcher is nuts!!!"; break;
		case 102: .@talk$ = "Huh, we're coming too!"; break;
		case 103: .@talk$ = "Hey, come quickly!!"; break;
		case 104: .@talk$ = "Spare me!!"; break;
		case 105: .@talk$ = "Good job!"; break;
		case 106: .@talk$ = "You're doing great, gunmen!"; break;
		case 107: .@talk$ = "Now!"; break;
		case 108: .@talk$ = "Oh, did you hear that? You should shoot now!"; break;
		case 109: .@talk$ = "Are they gone?"; break;
		case 110: .@talk$ = "Huh... uh.."; break;		
		case 111: .@talk$ = "Hey, are you okay?"; break;
		case 112: .@talk$ = "Ah... argh!! I'm... gonna die!!"; break;
		case 113: .@talk$ = "I don't think so..."; break;
		case 114: .@talk$ = "We'll help you!"; break;
	}
	npctalk .@talk$,.@npc$,bc_self;
	return;
}

sp_cor,163,79,0	script	#171_OS_EV	HIDDEN_WARP_NPC,7,5,{
	end;
	
OnTouch:
	if(ep_illusion == 36 || ep_illusion == 37){
		cloaknpc("Worker#os_poor",false,getcharid(0));
		cloaknpc("Worker#os_moc",false,getcharid(0));
		cloaknpc("Worker#os_cook",false,getcharid(0));
		cloaknpc("Worker#os_man",false,getcharid(0));
		cloaknpc("Tess#os_rb",false,getcharid(0));
		cloaknpc("Kaya#os_rb",false,getcharid(0));
		cloaknpc("Ashley#os_rb",false,getcharid(0));
		cloaknpc("Magenta#os_rb",false,getcharid(0));
		cloaknpc("Denny#os_rb",false,getcharid(0));
		cloaknpc("Tommy#os_rb",false,getcharid(0));
		cloaknpc("Gonie#os_rb",false,getcharid(0));
	}
end;
}

sp_cor,168,81,7	script	Advanced Team#171_cor	4_F_REBELLION3,{
	switch(ep_illusion){
		case 35:
			.@old$ = "Worker#os_old";
			.@poor$ = "Worker#os_poor";
			.@moc$ = "Worker#os_moc";
			.@cook$ = "Worker#os_cook";
			.@man$ = "Worker#os_man";
			mes "[ Worker ]";
			mes "Show me the way out!";
			171_worker_talk(1,.@old$);
			next;
			cloaknpc("Worker#os_poor",false,getcharid(0));
			cloaknpc("Worker#os_moc",false,getcharid(0));
			mes "[ Worker ]";
			mes "So these gunmen think they can just come here and start a commotion!";
			171_worker_talk(2,.@poor$);
			171_worker_talk(3,.@moc$);
			171_worker_talk(4,.@old$);
			next;
			mes "[ Advanced Team ]";
			mes "Gentlemen, please don't do this. We didn't come here to harm you.";
			next;
			cloaknpc("Worker#os_cook",false,getcharid(0));
			cloaknpc("Worker#os_man",false,getcharid(0));
			mes "[ Worker ]";
			mes "Of course not. We're just getting attacked by rebellions.";
			171_worker_talk(5,.@man$);
			171_worker_talk(6,.@poor$);
			171_worker_talk(7,.@moc$);
			171_worker_talk(8,.@cook$);
			171_worker_talk(9,.@old$);
			next;
			mes "[ Advanced Team ]";
			mes "Being emotional doesn't help resolve problems.";
			next;
			mes "[ Worker ]";
			mes "Are you threatening us now?";
			171_worker_talk(10,.@man$);
			next;
			select("What's going in?");
			mes "[ Advanced Team ]";
			mes "Aah! You're alive! Adventurer! Has anyone else come with you?";
			171_worker_talk(11,.@poor$);
			next;
			select("I'm the first to arrive...");
			mes "[ Advanced Team ]";
			mes "I sent a person to pick the person in charge. We are the Advanced Team who was sent here to search and organize this place, as you can see.";
			next;
			select("Who are these people?");
			mes "[ Worker ]";
			mes "Is this the person responsible for all of this?";
			171_worker_talk(12,.@cook$);
			171_worker_talk(13,.@man$);
			171_worker_talk(14,.@old$);
			next;
			mes "[ Worker ]";
			mes "I don't think so? That person looks stupid.";
			171_worker_talk(15,.@cook$);
			next;
			mes "[ Advanced Team ]";
			mes "They are the ^0000CDpeople who work here^000000.";
			mes "As you can see, we didn't harm them...";
			next;
			mes "[ Advanced Team ]";
			mes "I really don't know what to do.";
			mes "There are ^0000FFworkers from the lab^000000";
			mes "who do chores around here, and when we tried to enter they stopped us.";
			next;
			mes "[ Worker ]";
			mes "What are you saying does chores?";
			171_worker_talk(16,.@moc$);
			171_worker_talk(17,.@man$);
			next;
			mes "[ Worker ]";
			mes "Why do you guys judge the work of others? You aren't in charge, are you?";
			171_worker_talk(18,.@old$);
			171_worker_talk(19,.@poor$);
			next;
			mes "[ Worker ]";
			mes "I think you're just ignorant people who don't know anything.";
			171_worker_talk(20,.@moc$);
			next;
			mes "[ Worker ]";
			mes "Come on, they're all gunmen!";
			171_worker_talk(21,.@old$);
			next;
			mes "[ Advanced Team ]";
			mes "That's not it! We want to protect the civilians and make things right!";
			next;
			mes "[ Worker ]";
			mes "If we refuse to comply, what's gonna happen? Are you going to shoot us?";
			171_worker_talk(22,.@moc$);
			sleep2 2000;
			171_worker_talk(23,.@poor$);
			next;
			select("Why are you blocking the road?");
			mes "[ Worker ]";
			mes "Why not? If someone came into your home, would you just let them in?";
			mes "These people are out of their minds and are making a mess.";
			171_worker_talk(24,.@man$);
			next;
			mes "[ Worker ]";
			mes "See! Why are you sticking your nose into other people's business?";
			mes "That's it! Get out! Get out now!";
			171_worker_talk(25,.@cook$);
			next;
			mes "[ Advanced Team ]";
			mes "Perhaps you don't know, but this ^0000FFlab was doing illegal experiments.^000000";
			mes "We have came to arrest the people responsible in cooperation with the Government and Rekenber.";
			next;
			mes "[ Worker ]";
			mes "What? What do you mean illegal experiments? Can you tell us where these illegal experiments were done?";
			171_worker_talk(26,.@poor$);
			next;
			mes "[ Advanced Team ]";
			mes "I know it's hard to believe, I'm having a hard time to believe it myself, but this is the place that was used to run illegal experiments.";
			171_worker_talk(27,.@moc$);
			next;
			select("Who owns this mansion?");
			select("I don't see any researchers here.");
			mes "[ Advanced Team ]";
			mes "Perhaps they ^0000FFescaped to the mansion.^000000";
			171_worker_talk(28,.@old$);
			171_worker_talk(29,.@moc$);
			171_worker_talk(30,.@cook$);
			next;
			mes "[ Advanced Team ]";
			mes "These people look like the manual workforce, they are not researchers.";
			next;
			mes "[ Advanced Team ]";
			mes "The people and the materials that are left behind in the rush of escaping are likely the good people left.";
			next;
			mes "[ Worker ]";
			mes "What are you saying about us?";
			171_worker_talk(31,.@cook$);
			next;
			mes "[ Worker ]";
			mes "What? Are we just garbage you can just throw away?";
			171_worker_talk(32,.@old$);
			next;
			mes "[ Worker ]";
			mes "How many researcher are like us!";
			mes "They can't keep this place running without us!";
			171_worker_talk(33,.@moc$);
			next;
			mes "[ Worker ]";
			mes "Get out now! This is Rekenber's laboratory! You're trespassing on private property!";
			171_worker_talk(34,.@man$);
			next;
			mes "[ Advanced Team ]";
			mes "What? What are we supposed to do now. We can't use force against unarmed civilians.";
			171_worker_talk(35,.@poor$);
			next;
			select("I would never hurt you guys.");
			mes "[ Worker ]";
			mes "Why should we stand back? You're the invaders!";
			171_worker_talk(36,.@cook$);
			171_worker_talk(37,.@man$);
			next;
			mes "[ Worker ]";
			mes "I don't want anybody to get hurt, you will hurt us with your weapons!";
			171_worker_talk(38,.@old$);
			next;
			mes "[ Advanced Team ]";
			mes "Should we charge in?";
			171_worker_talk(39,.@moc$);
			next;
			cloaknpc("Tess#os_rb",false,getcharid(0));
			cloaknpc("Kaya#os_rb",false,getcharid(0));
			cloaknpc("Ashley#os_rb",false,getcharid(0));
			cloaknpc("Magenta#os_rb",false,getcharid(0));
			cloaknpc("Denny#os_rb",false,getcharid(0));
			cloaknpc("Tommy#os_rb",false,getcharid(0));
			cloaknpc("Gonie#os_rb",false,getcharid(0));
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "Why would you charge in without orders?";
			171_worker_talk(40,.@poor$);
			171_worker_talk(41,.@cook$);
			next;
			select("Vice President! Tess!");
			cutin "",255;
			mes "[ Worker ]";
			mes "Why do you keep coming? Get out! Get out!";
			171_worker_talk(42,.@moc$);
			next;
			mes "[ Advanced Team ]";
			mes "These are employees who help the laboratory run, but they do not believe when I tell them they've been conducting illegal experiments.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Alright. Let me talk to them.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Who are you now?!";
			171_worker_talk(43,.@old$);
			ep_illusion = 36;
			setquest 17015;
			questinfo_refresh();
			end;
			
		case 36:
			mes "[ Advanced Team ]";
			mes "The Vice President wants to talk to them.";
			close;
			
		case 37:
			mes "[ Advanced Team ]";
			mes "Didn't Tess tell you to discuss countermeasures?";
			close;
			
		case 38:
			mes "[ Advanced Team ]";
			mes "Go to the safe location, quick!";
			close;
			
		default:
			mes "[ Advanced Team ]";
			mes "Adventurer, it's dangerous here. Proceed to the safe location.";
			close;
	}
			
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 35");
end;
}

sp_cor,167,79,1	script	Advanced Team#171_cor2	4_F_REBELLION2,{
	switch(ep_illusion){
		case 35:
			mes "[ Advanced Team ]";
			mes "That's the problem. We can't push them by force. What should we do?";
			close;
			
		case 36:
			mes "[ Advanced Team ]";
			mes "Didn't you say the Vice President of Rekenber was going to convince them? What do you want to talk to me about?";
			close;
			
		case 37:
			mes "[ Advanced Team ]";
			mes "I don't think this is going to work. What do you think Tess will say? The fight is still going on.";
			close;
			
		default:
			mes "[ Advanced Team ]";
			mes "It's dangerous here. Move over to the safe area!";
			end;
	}
}

sp_cor,165,79,1	script	Kaya#os_rb	4_EP17_KAYA,{
	switch(ep_illusion){
		case 36:
			.@old$ = "Worker#171_old";
			.@poor$ = "Worker#os_poor";
			.@moc$ = "Worker#os_moc";
			.@cook$ = "Worker#os_cook";
			.@man$ = "Worker#os_man";
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Hello everyone, I'm Kaya Toss, Rekenber's Vice President.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Vice President? The Vice President?";
			mes "Isn't that another one of your lies?";
			171_worker_talk(44,.@moc$);
			next;
			mes "[ Worker ]";
			mes "Huh? I know him! That is indeed Kaya, The Vice President.";
			mes "When I was at the headquarters, I saw him a few times.";
			171_worker_talk(45,.@old$);
			next;
			mes "[ Worker ]";
			mes "Oh, really? I didn't know because I had never seen your face before.";
			171_worker_talk(46,.@cook$);
			171_worker_talk(47,.@poor$);
			next;
			mes "[ Worker ]";
			mes "Why is the Vice President here?";
			171_worker_talk(48,.@man$);
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Were you all hired by the Rekenber institute to work on constructing and maintenance in this new lab?";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "That's correct.";
			171_worker_talk(49,.@old$);
			next;
			mes "[ Worker ]";
			mes "Yes, I've been hired by Rekenber.";
			171_worker_talk(50,.@cook$);
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "What did the person wearing blue clothes over here do here?";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Me? Well... I'm responsible for making and delivering foods to the people working here.";
			171_worker_talk(51,.@cook$);
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "And what about the person next to you?";
			next;
			mes "[ Worker ]";
			mes "I carry waste materials and laboratory equipments.";
			171_worker_talk(52,.@poor$);
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "If you know what this place is studying, please raise your hand.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Well... renewable energy?";
			171_worker_talk(53,.@poor$);
			next;
			mes "[ Worker ]";
			mes "Oh I know! Wasn't it agricultural research?";
			171_worker_talk(54,.@moc$);
			next;
			mes "[ Worker ]";
			mes "It looks like livestock study.";
			mes "Sometimes strange beasts roam by.";
			171_worker_talk(55,.@man$);
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "While you do your own work, you don't know what this place is really for. in fact, I'm glad it's like that.";
			next;
			mes "[ Kaya ]";
			mes "This facility is doing illegal experiments that are strictly forbidden by the government and Rekenber.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "You mean, our researchers...? No way.";
			171_worker_talk(56,.@poor$);
			next;
			mes "[ Worker ]";
			mes "Those people were doing experiments outside of the law?";
			171_worker_talk(57,.@moc$);
			next;
			mes "[ Worker ]";
			mes "What illegal experiments?";
			171_worker_talk(58,.@cook$);
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "That, I don't know in details yet.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Can't you tell us more about what they've been doing?";
			171_worker_talk(59,.@old$);
			171_worker_talk(60,.@man$);
			next;
			mes "[ Worker ]";
			mes "You guys are supposed to be the good guys, then why do you call us the bad guys?";
			171_worker_talk(61,.@cook$);
			next;
			mes "[ Worker ]";
			mes "Exactly! That means these people have done bad things? Are the high members of Rekenber just going to come in and take the results of our scientists' research?";
			171_worker_talk(62,.@man$);
			next;
			mes "[ Worker ]";
			mes "Right? Otherwise, the Vice President wouldn't have brought the Rebellions, but the guards instead.";
			171_worker_talk(63,.@moc$);
			next;
			mes "[ Worker ]";
			mes "Are they really from the Enterprise? Why did the Vice President come here without the operatives?";
			171_worker_talk(64,.@poor$);
			next;
			mes "[ Worker ]";
			mes "Are you acting alone?";
			171_worker_talk(65,.@old$);
			next;
			mes "[ Worker ]";
			mes "He does look like the Vice President though.";
			171_worker_talk(66,.@cook$);
			171_worker_talk(67,.@man$);
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "This is a big problem. They don't believe us at all.";
			next;
			cutin "",255;
			mes "[ Advanced Team ]";
			mes "I mean, how do you think the researchers have brainwashed these people over the years?";
			171_worker_talk(68,.@cook$);
			next;
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "I'll talk to them, let me try.";
			171_worker_talk(69,.@old$);
			next;
			mes "[ Tess ]";
			mes "Hello everyone. My name is Tess, I'm fron the office of the President of Schwarzwald.";
			171_worker_talk(70,.@poor$);
			171_worker_talk(71,.@moc$);
			next;
			mes "[ Tess ]";
			mes "Some time ago, the Rekenber's laboratories have been under investigation because of their illegal experiments.";
			mes "We've been cooperating with the Vice President over here.";
			npctalk "Okay, well there's nothing here, so go back!",.@man$,bc_self;
			next;
			mes "[ Tess ]";
			mes "The Regenschirm lab, back at Rekenber, was involved with similar experiments and it caused a turmoil.";
			mes "If you refuse to cooperate, you will be charged with illegal acts and  your refusal to cooperate.";
			171_worker_talk(72,.@poor$);
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Are you threatening us now?";
			171_worker_talk(73,.@man$);
			next;
			mes "[ Worker ]";
			mes "No way! have we done anything wrong?";
			171_worker_talk(74,.@old$);
			next;
			mes "[ Worker ]";
			mes "This is our only job!";
			171_worker_talk(75,.@cook$);
			next;
			mes "[ Worker ]";
			mes "What gives you the right to just come here and charge us? We've been living her quietly for years. Did we sin?";
			171_worker_talk(76,.@moc$);
			next;
			cutin "ep16_tes02",2;
			mes "[ Tess ]";
			mes "Look around you. Even though you're having a hard time here, do you see any researcher trying to explain themselves?";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "oh, they must just be busy!";
			171_worker_talk(77,.@old$);
			next;
			mes "[ Worker ]";
			mes "They aren't as free as you are, they have work to do!";
			171_worker_talk(78,.@poor$);
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "There are no words to convince them.";
			171_worker_talk(79,.@moc$);
			next;
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "Hmmm... I won't be able to conclude this, let's take a moment to discuss.";
			171_worker_talk(80,.@cook$);
			completequest 17015;
			setquest 17016;
			ep_illusion = 37;
			questinfo_refresh();
			close3;
			
		case 37:
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Even when I tried to persuade them, they didn't listen. It's not easy to change someone's mind. I should discuss it with Tess.";
			close3;
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 36");
end;
}

sp_cor,166,81,7	script	Tess#os_rb	4_M_PHILOFONTES,{
	switch(ep_illusion){
		case 36:
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "The Vice President, Kaya Tess, is going to persuade them. Let's listen to him.";
			close3;
			
		case 37:
			.@old$ = "Worker#171_old";
			.@poor$ = "Worker#os_poor";
			.@moc$ = "Worker#os_moc";
			.@cook$ = "Worker#os_cook";
			.@man$ = "Worker#os_man";
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "I can't get through to them just with words.";
			171_worker_talk(81,.@moc$);
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "You cannot use force against innocent people.";
			171_worker_talk(82,.@old$);
			next;
			cutin "ep16_tes02",2;
			mes "[ Tess ]";
			mes "Even so, we might have to. We split in two teams, one of them keeps them from pursuing, and the rest enter and keep investigating.";
			171_worker_talk(83,.@poor$);
			171_worker_talk(84,.@moc$);
			next;
			cutin "ep171_kaya01",0;
			mes "[ Kaya ]";
			mes "That sounds like a good idea.";
			171_worker_talk(85,.@old$);
			next;
			cloaknpc("Elyumina#os_rb",false,getcharid(0));
			cloaknpc("Mercenary#os_rb_1",false,getcharid(0));
			cloaknpc("Mercenary#os_rb_2",false,getcharid(0));
			specialeffect EF_TELEPORTATION2,AREA,"Elyumina#os_rb";
			specialeffect EF_TELEPORTATION2,AREA,"Mercenary#os_rb_1";
			specialeffect EF_TELEPORTATION2,AREA,"Mercenary#os_rb_2";
			cutin "ep171_elyumina02",2;
			mes "[ ??? ]";
			mes "Don't move!";
			next;
			mes "[ ??? ]";
			mes "Everything here is mine! I won't let you harm my friends! I'm not messing around!";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Huh, senior researcher?";
			171_worker_talk(86,.@cook$);
			next;
			mes "[ Worker ]";
			mes "Elyumina?";
			171_worker_talk(87,.@old$);
			next;
			cutin "ep171_elyumina02",2;
			mes "[ Elyumina ]";
			mes "Who gave you permission to approach my staff? You see them? Just try putting one hand on them, and I'll blow you up.";
			171_worker_talk(88,.@moc$);
			next;
			cutin "ep171_elyumina04",2;
			mes "[ Elyumina ]";
			mes "No matter how stupid you are, it's always better to have your hands on your wrists, right?";
			171_worker_talk(89,.@man$);
			next;
			cutin "ep171_as02",0;
			mes "[ Ashley ]";
			mes "Everyone get back! It's dangerous!";
			171_worker_talk(90,.@poor$);
			next;
			cutin "ep171_elyumina03",2;
			mes "[ Elyumina ]";
			mes "You all look like skeletons, why aren't you hiding? You will all disappear!";
			next;
			specialeffect EF_RAIN_PARTICLE2,AREA,"Elyumina#os_rb";
			cutin "",255;
			mes "[ Worker ]";
			mes "Aaaaah!! Researcher! It's us! We're here too!";
			171_worker_talk(91,.@man$);
			171_worker_talk(92,.@poor$);
			171_worker_talk(93,.@old$);
			171_worker_talk(94,.@moc$);
			171_worker_talk(95,.@cook$);
			next;
			cutin "ep171_elyumina02",2;
			mes "[ Elyumina ]";
			mes "You know what! If you have soybeans and rice, which one do you choose?";
			mes "If you're in a hurry, you'll just mix them up!";
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_2";
			specialeffect EF_IGN_STR,AREA,"Worker#os_poor";
			specialeffect EF_MAGMA_FLOW,AREA,"Worker#os_poor";
			classchange(4_M_DIEMAN,"Worker#os_poor",bc_self);
			171_worker_talk(96,.@moc$);
			171_worker_talk(97,.@old$);
			next;
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_1";
			specialeffect EF_IGN_STR,AREA,"Worker#os_moc";
			specialeffect EF_MAGMA_FLOW,AREA,"Worker#os_moc";
			classchange(4_M_DSTMANDEAD,"Worker#os_moc",bc_self);
			cutin "",255;
			mes "[ Worker ]";
			mes "Why are you doing this?!!";
			171_worker_talk(98,.@man$);
			171_worker_talk(99,.@moc$);
			171_worker_talk(100,.@cook$);
			next;
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_1";
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_2";
			cutin "ep171_as02",0;
			mes "[ Ashley ]";
			mes "Now! Stand behind me!";
			171_worker_talk(101,.@old$);
			sleep2 300;
			cloaknpc("Ashley#os_rb",true,getcharid(0));
			sleep2 300;
			cloaknpc("Ashley#os_rb_2",false,getcharid(0));
			sleep2 500;
			171_worker_talk(102,.@man$);
			171_worker_talk(103,.@cook$);
			171_worker_talk(104,.@old$);
			sleep2 300;
			cloaknpc("Kaya#os_rb",true,getcharid(0));
			cloaknpc("Tess#os_rb",true,getcharid(0));
			cloaknpc("Worker#171_old",true,getcharid(0));
			cloaknpc("Worker#os_cook",true,getcharid(0));
			cloaknpc("Worker#os_man",true,getcharid(0));
			sleep2 300;
			.@old$ = "Worker#171_old_2";
			.@cook$ = "Worker#os_cook_2";
			.@man$ = "Worker#os_man_2";
			cloaknpc("Kaya#os_rb_2",false,getcharid(0));
			cloaknpc("Tess#os_rb_2",false,getcharid(0));
			cloaknpc("Worker#171_old_2",false,getcharid(0));
			cloaknpc("Worker#os_cook_2",false,getcharid(0));
			cloaknpc("Worker#os_man_2",false,getcharid(0));
			next;
			cutin "",255;
			mes "[ Advanced Team ]";
			mes "Everyone, formation!";
			cloaknpc("Denny#os_rb",true,getcharid(0));
			cloaknpc("Magenta#os_rb",true,getcharid(0));
			cloaknpc("Tommy#os_rb",true,getcharid(0));
			cloaknpc("Gonie#os_rb",true,getcharid(0));
			sleep2 500;
			cloaknpc("Denny#os_rb_2",false,getcharid(0));
			cloaknpc("Magenta#os_rb_2",false,getcharid(0));
			cloaknpc("Tommy#os_rb_2",false,getcharid(0));
			cloaknpc("Gonie#os_rb_2",false,getcharid(0));
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_1";
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_2";
			next;
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_1";
			specialeffect EF_DESPERADO,AREA,"Advanced Team#171_cor";
			specialeffect EF_SUI_EXPLOSION,AREA,"Elyumina#os_rb";
			cutin "ep171_elyumina02",2;
			mes "[ Elyumina ]";
			mes "You brought more people...";
			171_worker_talk(105,.@cook$);
			171_worker_talk(106,.@man$);
			next;
			specialeffect EF_DESPERADO,AREA,"Gonie#os_rb_2";
			specialeffect EF_DESPERADO,AREA,"Denny#os_rb_2";
			specialeffect EF_DESPERADO,AREA,"Magenta#os_rb_2";
			specialeffect EF_DESPERADO,AREA,"Tommy#os_rb_2";
			specialeffect EF_DESPERADO,AREA,"Advanced Team#171_cor";
			specialeffect EF_DESPERADO,AREA,"Advanced Team#171_cor2";
			mes "[ Elyumina ]";
			mes "What, what? Come on? Why is my attack... not working...?";
			171_worker_talk(107,.@cook$);
			171_worker_talk(108,.@old$);
			next;
			cutin "",255;
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_1";
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_2";
			mes "[ Mercenary 1 ]";
			mes "Avoid that!";
			next;
			specialeffect EF_RAPIDSHOWER,AREA,"Gonie#os_rb_2";
			specialeffect EF_RAPIDSHOWER,AREA,"Denny#os_rb_2";
			specialeffect EF_RAPIDSHOWER,AREA,"Tommy#os_rb_2";
			cutin "ep171_elyumina02",2;
			mes "[ Elyumina ]";
			mes "Why? Why are they not hurt? What about this?";
			next;
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_2";
			cutin "",255;
			mes "[ Mercenary 2 ]";
			mes "Oh, I've been struck! Hurry!";
			next;
			cutin "ep171_elyumina02",2;
			mes "[ Elyumina ]";
			mes "Why are they doing so well? Did we pick the wrong subjects?";
			next;
			specialeffect EF_RAPIDSHOWER,AREA,"Advanced Team#171_cor";
			specialeffect EF_RAPIDSHOWER,AREA,"Advanced Team#171_cor2";
			specialeffect EF_RAPIDSHOWER,AREA,"Magenta#os_rb_2";
			specialeffect EF_SUI_EXPLOSION,AREA,"Elyumina#os_rb";
			cutin "",255;
			mes "[ Mercenary 1 ]";
			mes "They are professionals!";
			next;
			cutin "ep171_elyumina02",2;
			mes "[ Elyumina ]";
			mes "You are pros!";
			next;
			specialeffect EF_DESPERADO,AREA,"Mercenary#os_rb_2";
			cutin "",255;
			mes "[ Mercenary 2 ]";
			mes "I'm also a high-end pro who gets money!! I don't have to cover the heat! Hurry!";
			next;
			specialeffect EF_RAPIDSHOWER,AREA,"Gonie#os_rb_2";
			specialeffect EF_RAPIDSHOWER,AREA,"Denny#os_rb_2";
			specialeffect EF_RAPIDSHOWER,AREA,"Tommy#os_rb_2";
			cutin "ep171_elyumina02",2;
			mes "[ Elyumina ]";
			mes "No! Let me go! Quick! You have to avoid being crushed! Let me go! Let me go!!";
			next;
			specialeffect EF_TELEPORTATION2,AREA,"Elyumina#os_rb";
			specialeffect EF_TELEPORTATION2,AREA,"Mercenary#os_rb_1";
			specialeffect EF_TELEPORTATION2,AREA,"Mercenary#os_rb_2";
			cloaknpc("Elyumina#os_rb",true,getcharid(0));
			cloaknpc("Mercenary#os_rb_1",true,getcharid(0));
			cloaknpc("Mercenary#os_rb_2",true,getcharid(0));
			cutin "ep171_as02",0;
			mes "[ Ashley ]";
			mes "Is everyone alright?";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I'm okay, but the others...";
			171_worker_talk(109,.@man$);
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Huh.. uh...";
			171_worker_talk(110,.@moc$);
			171_worker_talk(111,.@old$);
			next;
			mes "[ Worker ]";
			mes "Ah.. argh!! I'm... gonna die!!";
			171_worker_talk(112,.@poor$);
			171_worker_talk(113,.@cook$);
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I'll move the people to a safe location.";
			next;
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "Let the rest of the people here look at where they went.";
			171_worker_talk(113,.@man$);
			next;
			mes "[ Tess ]";
			mes "Some should stay here to watch out in case they come back, the rest of us will head to the <NAVI>[safe place]<INFO>sp_cor,122,141,0,101,0</INFO></NAVI>!";
			ep_illusion = 38;
			completequest 17016;
			setquest 17017;
			close2;
			cutin "",255;
			cloaknpc("Denny#os_rb_2",true,getcharid(0));
			cloaknpc("Magenta#os_rb_2",true,getcharid(0));
			cloaknpc("Tommy#os_rb_2",true,getcharid(0));
			cloaknpc("Gonie#os_rb_2",true,getcharid(0));
			cloaknpc("Kaya#os_rb_2",true,getcharid(0));
			cloaknpc("Tess#os_rb_2",true,getcharid(0));
			cloaknpc("Ashley#os_rb_2",true,getcharid(0));
			cloaknpc("Worker#171_old_2",true,getcharid(0));
			cloaknpc("Worker#os_cook_2",true,getcharid(0));
			cloaknpc("Worker#os_man_2",true,getcharid(0));
			cloaknpc("Worker#os_moc",true,getcharid(0));
			cloaknpc("Worker#os_poor",true,getcharid(0));
			questinfo_refresh();
			end;		
	}
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,164,77,1	script	Ashley#os_rb	4_EP17_AS,{
	if(ep_illusion == 36){
		cutin "ep171_as01",2;
		mes "[ Ashley ]";	
		mes "The Vice President is going to convince them.";
	} else {
		cutin "ep171_as01",2;
		mes "[ Ashley ]";	
		mes "Didn't Tess tell you to take action? If you aren't prepared, you should do that now.";
	}
	close3;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}


sp_cor,162,73,7	script	Denny#os_rb	4_M_REBELLION3,{
	if(ep_illusion == 36){
		mes "[ Denny ]";
		mes "I'm so curious what the inside looks like~";
		close;
	} else {
		mes "[ Denny ]";
		mes "Wait, something's not right?";
		close;
	}
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,165,74,1	script	Magenta#os_rb	4_M_GUNSLINGER2,{
	if(ep_illusion == 36){
		mes "[ Magenta ]";
		mes "These people aren't armed? What are they playing at?";
		close;
	} else {
		mes "[ Magenta ]";
		mes "I don't feel so well. We should get ready.";
		close;
	}
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,170,84,3	script	Worker#171_old	4_M_05,{
	if(ep_illusion < 37){	
		mes "[ Worker ]";
		mes "Are you seeing this? Show yourselves! Come on out!";
		end;
	}	
	mes "[ Worker ]";
	mes "I don't know why I keep standing here. If only I could ask for something. They're monsters.";
	end;
}

sp_cor,163,62,3	script	Tommy#os_rb	4_M_GUNSLINGER2,{
	if(ep_illusion == 36){
		mes "[ Tommy ]";
		mes "It's nice here and quiet. If only I could get a day off...";
		close;
	}
	mes "[ Tommy ]";
	mes "What is this big building in front of us? I've never seen anything like this before.";
	close;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,168,75,7	script	Gonie#os_rb	4_M_GONY,{
	mes "[ Gonie ]";
	mes "......";
	close;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,172,80,1	script	Worker#os_cook	4_M_CHNCOOK,{
	mes "[ Worker ]";
	mes "I'll have a warm drink when this is over!!";
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,167,85,5	script	Worker#os_poor	4_M_LGTPOOR,{
	mes "[ Worker ]";
	mes "I came out to see what was that commotion, what is happening?!";
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,164,82,5	script	Worker#os_moc	4_M_DSTMAN,{
	mes "[ Worker ]";
	mes "Today is supposed to be day off, but what is this! Are you responsible for it commotion?";
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,161,80,5	script	Worker#os_man	4_M_03,{
	mes "[ Worker ]";
	mes "Who said it? Who's going to kick our butts?!";
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,165,86,5	duplicate(dummynpc)	Elyumina#os_rb	4_EP17_ELYUMINA
sp_cor,163,87,5	duplicate(dummynpc)	Mercenary#os_rb_1	3454
sp_cor,166,88,5	duplicate(dummynpc)	Mercenary#os_rb_2	3454
sp_cor,159,66,3	duplicate(dummynpc)	Worker#171_old_2	4_M_05
sp_cor,159,68,7	duplicate(dummynpc)	Tess#os_rb_2	4_M_PHILOFONTES
sp_cor,160,70,7	duplicate(dummynpc)	Kaya#os_rb_2	4_EP17_KAYA
sp_cor,163,75,7	duplicate(dummynpc)	Ashley#os_rb_2	4_EP17_AS
sp_cor,163,73,5	duplicate(dummynpc)	Worker#os_cook_2	4_M_CHNCOOK
sp_cor,162,72,5	duplicate(dummynpc)	Worker#os_man_2	4_M_03
sp_cor,165,82,0	duplicate(dummynpc)	Gonie#os_rb_2	4_M_GONY
sp_cor,162,83,0	duplicate(dummynpc)	Denny#os_rb_2	4_M_REBELLION3
sp_cor,162,80,7	duplicate(dummynpc)	Magenta#os_rb_2	4_M_GUNSLINGER2
sp_cor,171,84,1	duplicate(dummynpc)	Tommy#os_rb_2	4_M_GUNSLINGER2

//= Cor Main Area
sp_cor,122,141,5	script	Tess#sp_cor	4_M_PHILOFONTES,{
	switch(ep_illusion){
		case 38:
			cutin "ep16_tes01",0;
			mes "[ Tess ]";
			mes "Are you alright?";
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Was I really this late? What is all of this, why is everyone wounded?";
			npctalk "It's a mess, it's a total mess. I should have been here sooner.","Lazy#sp_cor",bc_self;
			next;
			cutin "ep16_tes01",0;
			mes "[ Tess ]";
			mes "You know what? Please help me out instead, I don't have time to explain.";
			npctalk "If you arrived a little sooner, you'd have a hole on your tongue.","",bc_self;
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Hey, I've been worried about all of this!";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "This is impossible... the chief researcher attacked us.";
			npctalk "Why did they do this...","Worker#os_red",bc_self;
			next;
			mes "[ Worker ]";
			mes "I was the one who made all this stuff and never once questioned it...";
			next;
			mes "[ Worker ]";
			mes "Why us...";
			npctalk "With such a person around... I'm scared now...","Worker#os_lady",bc_self;
			next;
			mes "[ Worker ]";
			mes "Hey, don't say that.";
			npctalk "What are you talking about?","Worker#os_sit",bc_self;
			next;
			mes "[ Worker ]";
			mes "Do you still believe in that researchers? Is that it?";
			npctalk "Really?","Worker#os_red",bc_self;
			next;
			mes "[ Worker ]";
			mes "Of course not... They're assassins.";
			next;
			cloaknpc("Ashley#sp_cor",true,getcharid(0));
			cloaknpc("Kaya#sp_cor",true,getcharid(0));
			sleep2 200;
			cloaknpc("Ashley#sp_cor2",false,getcharid(0));
			cloaknpc("Kaya#sp_cor2",false,getcharid(0));
			cutin "ep171_as02",0;
			mes "[ Ashley ]";
			mes "Please stay here, I will check the surroundings.";
			npctalk "Please stay here, I will check the surroundings.","Ashley#sp_cor2",bc_self;
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Let's look at the status of the wounded people.";
			npctalk "Let's look at the status of the wounded people.","Kaya#sp_cor2",bc_self;
			next;
			cloaknpc("Ashley#sp_cor2",true,getcharid(0));
			sleep2 200;
			cloaknpc("Ashley#sp_cor",false,getcharid(0));
			cutin "ep171_as02",0;
			mes "[ Ashley ]";
			mes "Alright, please stay here though.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Do you know who she was?";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Yes, she's one of the senior researchers, her name is ^0000FFElyumina.^000000";
			npctalk "There is a nice song in the yard.","Worker#os_red",bc_self;
			next;
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "It was stupid thing to come and attack directly. What are they studying?";
			unittalk getcharid(3),strcharinfo(0) + " : I'd rather say the combatants on both sides were wrong.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "That's because I'm the only mechanic in the lab. I don't care about anything other than my own machines...";
			next;
			mes "[ Worker ]";
			mes "Now that I think about it, her eyes were not normal. She looks like a crazy person.";
			npctalk "Yeah. She used to laugh strangely before.","Worker#os_lady",bc_self;
			next;
			mes "[ Worker ]";
			mes "Have you evere seen her room? I was frightened when I saw it the first time. She closed the door quicly, but I saw it.";
			npctalk "I've seen some signs too.","Worker#os_sit",bc_self;
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Are you saying you've witnessed an illegal experiment?";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Yeah, maybe it was. These machines moved strangely. Huh...";
			npctalk "Why are you only saying this now?","Worker#os_stand",bc_self;
			next;
			cutin "ep16_tes02",2;
			mes "[ Tess ]";
			mes "Do you believe what we've been saying now?";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Yes, I believe you! Fully believe you now!";
			npctalk "We all believe you!","Worker#os_red",bc_self;
			next;
			mes "[ Worker ]";
			mes "We can definitely trust the Vice President!";
			npctalk "No!","Worker#os_lady",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Good. We can continue with our investigation now. Vice President, give me your documents.";
			npctalk "What investigation?","Worker#os_sit",bc_self;
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "What documents?";
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "The list of missing people. I need to double check with who we have here.";
			npctalk "If you could line up, that would be nice.","Lazy#sp_cor",bc_self;
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "Here, stand in line please. Make three rows. Please tell me your full name when your turn comes.";
			npctalk "Let me do it first, I think I'll die soon.","Worker#os_stand",bc_self;
			next;
			cloaknpc("Ashley#sp_cor",true,getcharid(0));
			sleep2 200;
			cloaknpc("Ashley#sp_cor2",false,getcharid(0));
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "Vice President, a moment please...";
			mes "I have something I want to discuss.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "What's going on?";
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "Not here, please come <NAVI>[here]<INFO>sp_cor,135,147,0,101,0</INFO></NAVI>.";
			ep_illusion = 39;
			completequest 17017;
			setquest 17018;
			cloaknpc("Ashley#sp_cor2",true,getcharid(0));
			sleep2 200;
			cloaknpc("Ashley#sp_cor",false,getcharid(0));
			close3;
			
		case 39:
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "Didn't you see <NAVI>[Ashley]<INFO>sp_cor,135,147,0,000,0</INFO></NAVI> going with the Vice President? I'm worried about the wounded people.";
			close3;
			
		default:
			cutin "ep16_tes01",2;
			mes "[ Tess ]";
			mes "It will take some time to finish the investigation and gather all the data here.";
			close3;
	}
	end;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 38";
end;
}

sp_cor,137,146,3	script	Kaya#sp_cor	4_EP17_KAYA,{
	switch(ep_illusion){
		case 39:
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "It looks like <NAVI>[Ashley]<INFO>sp_cor,135,147,0,101,0</INFO></NAVI> is concerned about the wounded people. Let's go see what she wants to talk about.";
			close3;
			
		default:
			if(ep_illusion > 39)
				break;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I hope we can find all the missing people. I really hope we do.";
			close3;
	}
	switch(finding_patrick){
		case 0:
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Adventurer. Could I speak with you for a moment please?";
			next;
			select("What's the matter?");
			mes "[ Kaya ]";
			mes "You and others previously attacked a lab that's been conducting illegal experiments.";
			mes "What do you think about this one?";
			next;
			select("I think this lab is the same.:I don't know");
			mes "[ Kaya ]";
			mes "I think this lab has also been doing illegal experiments. So... could I ask you a favor?";
			next;
			mes "[ Kaya ]";
			mes "I think this is the laboratory where the ^0000FFmissing people were sent to.^000000 Besides the people in this area, there might be other that can't see right now.";
			next;
			select("....");
			mes "[ Kaya ]";
			mes "I would like you to ^0000FFcontinue investigating Patrick Kaufman.^000000";
			mes "Maybe if he worked here, the others might know something about it.";
			next;
			cutin "ep171_kaya02",2;
			mes "[ Kaya ]";
			mes "Maybe... this is the last chance we'll ahve to find Patrick after all.";
			next;
			if(select("I'll look into it.:I have something else to do right now.") == 2){
				cutin "ep171_kaya01",2;
				mes "[ Kaya ]";
				mes "It's okay, you don't have to look right now. There are other urgent matters to take care of.";
				next;
				mes "[ Kaya ]";
				mes "But please think of Kaufman when you can later.";
				close3;
			}
			mes "[ Kaya ]";
			mes "Thank you. I'm sorry to have had to ask you this so suddenly.";
			setquest 17020;
			finding_patrick = 1;
			questinfo_refresh();
			close3;
			
		case 8:
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Oh, welcome back adventurer. Come. Kaufman, did you find him?";
			next;
			select("I have... this bracelet.");
			mes "[ Kaya ]";
			mes "Those are...? What is this?";
			delitem 25666,1;
			next;
			select("This is an identification bracelet.");
			mes "[ Kaya ]";
			mes "This is Kaufman's...? Were there other people there?";
			next;
			cutin "",255;
			mes "- Told Kaya the story about the researcher you met at Rudus and about the experiments.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Why didn't the researcher come back with you?";
			next;
			select("She didn't want to come back...");
			mes "[ Kaya ]";
			mes "I see...";
			next;
			mes "[ Kaya ]";
			mes "Alright. Later, I will send a specialist to look for a body or remains. Again, I must reward you for your services.";
			next;
			mes "[ Kaya ]";
			mes "If time permits, I hope you will give these experiments a proper rest. There is no one other than you, the adventurer, to see this through.";
			next;
			cutin "ep171_kaya02",2;
			mes "[ Kaya ]";
			mes "I'm sorry to keep asking these hard task for you. If you bring me their bracelets, I will reward you.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I will go back to the headquarters with the missing people list. I'll use the bracelets as evidence and send the necessary compensation to their families.";
			next;
			mes "[ Kaya ]";
			mes "All future work will be handled through ^0000FFAshley over here^000000. I will hand the bracelets to Ashley.";
			next;
			mes "[ Kaya ]";
			mes "Thank you for everything you've done so far.";
			finding_patrick = 9;
			completequest 17032;
			getexp 600000,600000;
			getitem 25723,20;
			close3;
			
		default:
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I would like you to continue investigating Patrick Kaufman.";
			mes "Maybe if he worked here, the others might know something about it.";
			close3;	
	}
	end;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion > 39 && finding_patrick == 0";
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion > 39 && finding_patrick == 8";
end;
}

sp_cor,125,140,5	script	Kaya#sp_cor2	4_EP17_KAYA,{
	if(ep_illusion == 39){
		cutin "ep171_kaya01",2;
		mes "[ Kaya ]";
		mes "It looks like <NAVI>[Ashley]<INFO>sp_cor,135,147,0,000,0</INFO></NAVI> is concerned about the wounded people. Let's go see what she wants to talk about.";
		close3;
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,135,147,3	script	Ashley#sp_cor	4_EP17_AS,{
	switch(ep_illusion){
		case 39:
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "This way.";
			next;
			cloaknpc("Kaya#sp_cor2",true,getcharid(0));
			sleep2 200;
			cloaknpc("Kaya#sp_cor",false,getcharid(0));
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "What's the status of the wounded people?";
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "They're being looked at seriously, but we're also getting some paperwork done about them.";
			npctalk "Paperwork?","Kaya#sp_cor",bc_self;
			next;
			mes "[ Ashley ]";
			mes "As we started treating them, we've found some ^0000FFserious health issues^000000 in addition to their injuries.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Tell me more.";
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "It seems they were ^0000FFpoisoned^000000 while moving waste materials and their clothes were contaminated by various dangerous substances used in the lab because they didn't have safety equipment.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "She didn't even follow basic safety rules. How many have been poisoned?";
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "Yes, only the people resting over there...";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Am I... dead?";
			npctalk "I haven't eaten too much!","Worker#os_sit",bc_self;
			next;
			cutin "ep171_as02",0;
			mes "[ Ashley ]";
			mes "Oh! The reporting site wasn't looking too good!";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "But, when I die... what about my family... my family...";
			npctalk "I don't want to die. Please, bring me some hope.","Worker#os_stand",bc_self;
			next;
			cutin "ep171_as03",0;
			mes "[ Ashley ]";
			mes "Don't worry, you won't die.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Didn't you say we were about to die?";
			next;
			cutin "ep171_as03",0;
			mes "[ Ashley ]";
			mes "I said your bodies weren't healthy, but who said anything about dying?";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Can I rest? Shouldn't I get back to work? If I don't work, my family will starve.";
			npctalk "If you can't work, you can't live.","Worker#os_red",bc_self;
			next;
			mes "[ Worker ]";
			mes "Hey, what about me!";
			next;
			mes "[ Worker ]";
			mes "I'm sick too! If I sleep, it will be cured in a day!";
			npctalk "Oh please! Stop talking!","Worker#os_stand",bc_self;
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "Oh. About that. You need professional treatment and care.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "No, it's not okay. I have to... I need to work.";
			npctalk "I'm hurt!","Worker#os_sit",bc_self;
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "Then you'll really die. I don't think you want to die yet, right?";
			mes "If you keep working, you will. You need to rest and be treated by professionals.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I can't keep working as the Vice President while the Enterprise is in this state.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Are you going to just get rid of us? If it's not you, it'll be someone else!";
			npctalk "I'm sorry, we can't win!","Worker#os_red",bc_self;
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I'll be taking care of this disaster instead. I will do everything to ensure your full recovery.";
			npctalk "I'm sure it was an accident.","Worker#os_lady",bc_self;
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "I'm glad to hear not all of you are bad people.";
			npctalk "But what about the rest of the workforce?","Worker#os_stand",bc_self;
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "If you are unhealthy, you should focus on getting better first.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "My Angela... I'll finally be able to see my Angela again....";
			next;
			mes "[ Worker ]";
			mes "But, well... what about us? We're in a relationship...";
			npctalk "What about me, I'm too old!","Worker#os_red",bc_self;
			next;
			mes "[ Worker ]";
			mes "Still, I want to keep working. We can write anywhere right? If we had a seat back at our headquarters...";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "I do not know if there are jobs available back at headquarters.";
			mes "I'll check up on that once.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Isn't there ^0000FFa lot of work^000000 to do here too? There's still waste materials... right? But I don't think the gunmen will stay here for more than a day or two.";
			next;
			mes "[ Worker ]";
			mes "You know, we need people to chop trees, cook, clean, and who will wash our clothes? I don't think it's possible.";
			npctalk "I want some delicious rice.","Worker#os_sit",bc_self;
			next;
			mes "[ Worker ]";
			mes "What? Are we even strong enough to eat food?";
			next;
			mes "[ Worker ]";
			mes "No way... we know where to catch the fishes... where the good mushrooms are... where the best spots for the bathroom are... you guy don't know any of that.";
			npctalk "We're all going to die here.","Worker#os_lady",bc_self;
			next;
			mes "[ Worker ]";
			mes "She's right! Nobody else knows this place as much as we do.";
			npctalk "I know where my delicious raspberries are...","Worker#os_red",bc_self;
			next;
			cutin "ep171_as01",0;
			mes "[ Ashley ]";
			mes "I understand what they're saying.";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Hmm... well, I guess we need to keep people here who knows this place. Alright, I've decided.";
			mes "Anyone who's in good enough shape and wishes to remain can stay here and they will still be hired.";
			next;
			cutin "",255;
			mes "[ Worker ]";
			mes "Oh my... thank you....";
			next;
			mes "[ Worker ]";
			mes "Thank you! Thank you!";
			npctalk "He's the Vice President. he has good connections.","Worker#os_red",bc_self;
			npctalk "Thank you.","Worker#os_lady",bc_self;
			npctalk "We can't thank you enough.","Worker#os_sit",bc_self;
			npctalk "Thank you! Thank you!","Worker#os_stand",bc_self;
			next;
			select("These people are victims too...");
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "As Lazy was saying, I think Rekenber has used these people because of their desperation.";
			next;
			cutin "",255;
			mes "[ Support Team ]";
			mes "We need support from the adventurer!";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "What is it? Are the wounded people okay?";
			next;
			cutin "",255;
			mes "[ Support Team ]";
			mes "We were tracking the attacker, some of us got injured and now we ^0000FFneed support.^000000";
			next;
			cutin "ep171_kaya01",2;
			mes "[ Kaya ]";
			mes "Attacker?";
			next;
			cutin "",255;
			mes "[ Support Team ]";
			mes "There were some traps set up, and some of us were injured because of it.";
			next;
			mes "[ Support Team ]";
			mes "The Advanced Team has difficulty searching everything on its own,";
			mes "the adventurer's help would be appreciated! Please join the Search Team on the <NAVI>[left]<INFO>sp_cor,108,130,0,000,0</INFO></NAVI>!";
			getexp 300000,300000;
			ep_illusion = 40;
			completequest 17018;
			setquest 17019;
			questinfo_refresh();
			end;
			
		default:
			if(finding_patrick >= 9)
				break;
			cutin "ep171_as02",2;
			mes "[ Ashley ]";
			mes "I honestly had no idea this place was hidden here. How the hell did they manage to avoid the surrounding people's attention?";
			close3;
	}
	switch(finding_patrick){
		case 9:	
			cutin "ep171_as01",2;
			mes "[ Ashley ]";
			mes "Hello. Do you need anything?";
			next;
			select("I'm going back to Rudus.:Is there anything I can help with?");
			mes "[ Ashley ]";
			mes "There is nothing else to ask of you adventurer.";
			next;
			mes "[ Ashley ]";
			mes "If you have time, how about you go back to Rudus and find more Identification Bracelets?";
			finding_patrick = 10;
			close3;
			
		case 10:
			switch(checkquest(17035,PLAYTIME)){
				case -1:
					break;
					
				case 0: case 1:
					cutin "ep171_as03",2;
					mes "[ Ashley ]";
					mes "Hello you're back already adventurer? What's the matter? Do you need anything?";
					next;
					select("I'm going to Rudus.");
					mes "[ Ashley ]";
					mes "Already? You've been there for a while today, no? Take a break it's not easy.";
					next;
					mes "[ Ashley ]";
					mes "I need some time to sort out the bracelets that you've brought earlier.";
					next;
					mes "[ Ashley ]";
					mes "I'll see you again at dawn.";
					close3;
					
				case 2:
					erasequest 17035;
					break;
			}
			switch(checkquest(17034)){
				case -1:
					cutin "ep171_as03",2;
					mes "[ Ashley ]";
					mes "Hello, are you going to Rudus?";
					next;
					if(select("Yes. I'll be going.:I can't go today.") == 2){
						cutin "ep171_as03",2;
						mes "[ Ashley ]";
						mes "It's alright, you need to take breaks as well, adventurer.";
						close3;
					}
					mes "[ Ashley ]";
					mes "It won't be easy, but plesae put to rest 20 ^0000FFDolors specimens^000000 and collect 10 ^0000FFIdentification Bracelets^000000 from them. Thank you, and again, please be careful.";
					next;
					cutin "ep171_as01",2;
					mes "[ Ashley ]";
					mes "I know you will do well.";
					setquest 17034;
					close3;
					
				case 1:
					switch(checkquest(17034,HUNTING)){
						case 1:
							cutin "ep171_as01",2;
							mes "[ Ashley ]";
							mes "Have you finished the work in Rudus?";
							next;
							mes "[ Ashley ]";
							mes "Oh... huh, I thought the Vice President told you to put them to rest?";
							close3;
							
						case 2:
							if(countitem(25666) < 10){
								cutin "ep171_as01",2;
								mes "[ Ashley ]";
								mes "Have you finished the work in Rudus?";
								next;
								mes "[ Ashley ]";
								mes "Oh... huh, I thought the Vice President told you to put them to rest?";
								close3;
							}
							cutin "ep171_as01",2;
							mes "[ Ashley ]";
							mes "Have you finished the work in Rudus?";			
							next;
							cutin "ep171_as02",2;
							mes "[ Ashley ]";
							mes "You brought ^0000FF10 identification bracelet^000000... Alright, I received them.";
							delitem 25666,10;
							next;
							cutin "ep171_as01",2;
							mes "[ Ashley ]";
							mes "I will see you again at dawn.";
							mes "You must be pretty tired.";
							getexp 200000,200000;
							getitem 25723,1;
							getitem 25669,5;
							erasequest 17034;
							setquest 17035;
							close3;
					}
			}
			
	}
	end;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 39";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"checkquest(17034,HUNTING) == 2 && countitem(25666) >= 10";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"finding_patrick == 10 && checkquest(17035,PLAYTIME) == -1 && checkquest(17034,HUNTING) == -1";
	questinfo QTYPE_DAILYQUEST,QMARK_YELLOW,"finding_patrick == 10 && checkquest(17035,PLAYTIME) == 2";
end;
}

sp_cor,127,141,3	duplicate(dummynpc)	Ashley#sp_cor2	4_EP17_AS

sp_cor,124,139,1	script	Lazy#sp_cor_main	4_M_LAZY,{
	switch(ep_illusion){
		case 39:
			cutin "16lei_03",2;
			mes "[ Lazy ]";			
			mes "The <NAVI>[guard]<INFO>sp_cor,135,147,0,101,0</INFO></NAVI> seems to have something to say to the VIP. Is it a problem with the wounded people?";
			close3;
			
		default:
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Do you think this is where they are? I have to find the missing people.";
			close3;
	}
	end;
}

sp_cor,120,140,5	script	Rookie#sp_cor_main	4_M_ROOKIE,{
	cutin "16loo_01",2;
	mes "[ Rookie ]";
	mes "I really can't believe this place runs illegal experiments. It just looks too good?";
	close3;
}

sp_cor,121,138,7	script	Gonie#sp_cor_main	4_M_GONY,{
	cutin "16go_01",0;
	mes "[  ]";
	mes "......";
	close3;
}

sp_cor,108,130,5	script	Rebellion#os_merchant	4_F_REBELLION3,{
	switch(ep_illusion){
		case 40:
			mes "[ Rebellion ]";
			mes "You've been called! The captains are meeting. Elena Bolkova has called you too adventurer.";
			mes "I was just about to get her... but she just arrived.";
			cloaknpc("Elena Bolkova#sp_cor_main",false,getcharid(0));
			npctalk "Elena Bolkova : Ah, I was looking for you, adventurer.","Elena Bolkova#sp_cor_main",bc_self;
			if(isbegin_quest(17019) == 1)
				completequest 17019;
			if(isbegin_quest(16352) == 0)
				setquest 16352;
			questinfo_refresh();
			end;
			
		case 41:
			mes "[ Rebellion ]";
			mes "You've been called! The captains are meeting. Elena Bolkova has called you too adventurer.";
			mes "I was just about to get her... but she just arrived.";
			cloaknpc("Elena Bolkova#sp_cor_main",false,getcharid(0));
			npctalk "Elena Bolkova : Ah, I was looking for you, adventurer.","Elena Bolkova#sp_cor_main",bc_self;
			end;
			
		case 47:
			function weapon_mod; function armor_mod; function armor_rand; function weapon_rand;
			mes "[ Rebellion ]";
			mes "Did you bring a broken weapon?";
			mes "Looking for a scientist criminal?";
			mes "I deal everything. What do you need?";
			mes "Perhaps you need me? I'm replacing the weapon with modules.";
			npctalk "Hey criminal, someone's looking for you!","",bc_self;
			cloaknpc("Elyumina#os_merchant",false,getcharid(0));
			npctalk "Oh look at you! Give me a gun and I'll show you how to fight, not one of those bean bags!","Elyumina#os_merchant",bc_self;
			next;
			switch(select("I came to see Elyumina.:Request a weapon modification.:Request an armor modification.")){
				case 1:
					mes "[ Rebellion ]";
					mes "Yes, then go ahead and speak to her.";
					mes "I tried to work on them, but she decided to change the weapons and armors. She's good at it. She worked all day long.";
					close;
					
				case 2: weapon_mod();
				case 3: armor_mod();
			}
			end;
			
		default:
			mes "[ Rebellion ]";
			mes "This building is temporarily used by the Rebellion.";
			mes "We're occupying some other buildings too.";
			next;
			mes "[ Rebellion ]";
			mes "I'm rather busy.";
			mes "It's not like I'm pleased with the president and the Enterprise, but it's nice to feel like I'm doing something good.";
			close;			
	}
	end;
	
function	armor_rand	{
	.@size = getarraysize(.armor_mod$);
	.@index = rand(.@size);
	while(!.@bool){
		explode(.@T$,.armor_mod$[.@index],":");
		if(rand(1,100) <= atoi(.@T$[1])){
			.@bool = true;
			.@item_id = atoi(.@T$[0]);
			return .@item_id;
		}
		while(.@index == (.@size - 1))
			.@index = rand(.@size);
		.@index++;
	}
}

function	weapon_rand	{
	.@index = getarg(0);
	explode(.@T$,.weapon_mod$[.@index],",");
	.@size = getarraysize(.@T$);
	.@index = rand(.@size);
	while(!.@bool){
		explode(.@TT$,.@T$[.@index],":");
		if(rand(1,100) <= atoi(.@TT$[1])){
			.@bool = true;
			.@item_id = atoi(.@TT$[0]);
			return .@item_id;
		}
		while(.@index == (.@size - 1))
			.@index = rand(.@size);
		.@index++;
	}
}
	
function	armor_mod	{
	mes "[ Rebellion ]";
	mes "Do you need an armor modification module? I'll need 30 <ITEM>[Unknown Parts]<INFO>25669</INFO></ITEM> and 5 <ITEM>[Cor Cores]<INFO>25723</INFO></ITEM>.";
	mes "The modules are given at random.";
	next;
	if(select("Request Armor Modification Modules.:Cancel.") == 2) end;
	if(countitem(25669) < 30 || countitem(25723) < 5){
		mes "[ Rebellion ]";
		mes "You are missing parts, come back to me when you have complete parts.";
		end;
	}
	.@item_id = armor_rand();
	delitem 25669,30;
	delitem 25723,5;
	mes "[ Rebellion ]";
	mes "You paid for the Armor Modification module.";
	mes "The machine <NAVI>[next to me]<INFO>sp_cor,106,136,0,000,0</INFO></NAVI> will do well with these scrap metal pieces.";
	getitem .@item_id,1;
	end;
}

function	weapon_mod	{
	mes "[ Rebellion ]";
	mes "Do you need a weapon modication module? I'll need 5 <ITEM>[Cor Cores]<INFO>25723</INFO></ITEM> or 1M Zeny.";
	mes "If you need a weapon, Elyumina is going to make them for you. So talk to her.";
	next;
	if(select("Request a Weapon Modifier (Physical):Request a Weapon Modifier (Magical)") == 1)
		.@index = 0;
	else 
		.@index = 1;
	mes "[ Rebellion ]";
	mes "The normal outcome is random:";
	explode(.@T$,.weapon_mod$[.@index],",");
	for(.@i = 0; .@i < 3; .@i++){
		explode(.@TT$,.@T$[.@i],":");
		.@item_id[.@i] = atoi(.@TT$[0]);
		.@item_name$[.@i] = getitemname(.@item_id);
		mes "<ITEM>["+.@item_name$[.@i]+"]<INFO>"+.@item_id[.@i]+"</INFO></ITEM>";
	}
	mes "You will need 5 Cor Cores or ^0000FF1,000,000^000000 Zeny, which will it be?";
	next;
	if(select("Use 5 Cor Cores.:Spend 1,000,000 Zeny.") == 1){
		if(countitem(25723) < 5){
			mes "[ Rebellion ]";
			mes "You don't have enough Cor Cores";
			end;
		}
		delitem 25723,5;
	} else {
		if(Zeny < 1000000){
			mes "[ Rebellion ]";
			mes "You don't have enough zeny.";
			end;
		}
		Zeny -= 1000000;
	}
	.@module = weapon_rand(.@index);
	mes "[ Rebellion ]";
	mes "I've got the best out of this deal!";
	mes "The machine <NAVI>[next to me]<INFO>sp_cor,106,136,0,000,0</INFO></NAVI> will do well with these scrap metal pieces.";
	getitem .@module,1;
	end;
}

OnInit:
	setarray .armor_mod$,
	"25670:9","25671:9","25672:9","25673:9","25674:9","25675:9","25676:9","25677:9",
	"25678:7","25679:7","25680:7","25681:7","25682:7","25683:7","25684:7","25685:7","25686:7","25687:7","25688:7","25689:7","25690:7","25691:7","25692:7",
	"25693:5","25694:5","25695:5","25696:5","25697:5","25698:5","25699:5",
	"25700:3","25701:3","25702:3","25703:3","25704:3","25705:3";
	setarray .weapon_mod$,"23776:20,23777:15,23778:10","23779:20,23780:15,23781:10";
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 40 && isbegin_quest(16352) == 0";
end;
}

sp_cor,110,130,3	script	Elena Bolkova#sp_cor_main	4_F_ELENA,{
	switch(ep_illusion){
		case 40:
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "So, adventurer. Did you hear why I was looking for you?";
			mes "The researcher ran away during the riot at the entrance. As you can see, the search has been difficult.";
			next;
			mes "[ Elena Bolkova ]";
			mes "Huh, what is it?";
			specialeffect EF_SCREEN_QUAKE;
			sleep2 1000;
			next;
			cutin "",255;
			mes "[ Rebellion ]";
			mes "Captain there's been an explosion near a facility!";
			mes "It seems to be the researcher ^0000FFElyumina^000000! I will pursue immediately!";
			next;
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "That guy, he works so hard. It's a war zone now.";
			mes "That's right! " + strcharinfo(0) + ", follow me. Meet me over <NAVI>[there]<INFO>sp_cor,180,169,0,000,0</INFO></NAVI>!";
			ep_illusion = 41;
			completequest 16352;
			setquest 16353;
			close3;
			
		case 41:
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "An explosion occured near a facility. It must be Elyumina.";
			mes "I have to capture her this time, follow me over <NAVI>[there]<INFO>sp_cor,180,169,0,000,0</INFO></NAVI>!";
			close3;
	}	
	end;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 40 && isbegin_quest(16352) == 1";
	cloaknpc(strnpcinfo(0),true);
end;	
}

sp_cor,111,130,3	script	Elyumina#os_merchant	4_EP17_ELYUMINA,{
	function weapon; 
	function armor;
	cutin "ep171_elyumina04",0;
	mes "[ Elyumina ]";
	mes "What's up? If you call a busy person, you have to atleast talk to them, no?";
	next;
	if(select("Request OS Weapons.:Request Illusion Equipments.") == 1)
		weapon();
	else
		armor();
	end;

function	armor		{
	mes "[ Elyumina ]";
	mes "For Illusion Equipments, I will need 50 <ITEM>[Cor Cores]<INFO>25723</INFO></ITEM>.";
	mes "Let's see... this should be good, which one do you want?";
	next;
	.@s = select("Illusion Armor:Illusion Engine Wing:Illusion Leg:Illusion Booster:Illusion Battle Chip") - 1;
	explode(.@T$,.armor$[.@s],",");
	cutin "ep171_elyumina04",0;
	mes "[ Elyumina ]";
	for(.@i = 0; .@i < 2; .@i++){
		.@item_id[.@i] = atoi(.@T$[.@i]);
		.@item_name$[.@i] = getitemname(.@item_id[.@i]);
		.@menu$ +=  .@item_name$[.@i] + ":";
		mes "<ITEM>["+.@item_name$[.@i]+"]<INFO>"+.@item_id[.@i]+"</INFO></ITEM>";
	}
	mes "Which will it be?";
	next;
	.@s = select(.@menu$) - 1;
	mes "[ Elyumina ]";
	mes "Yeah, what you want is a " + .@item_name$[.@s] + ", right? I will need 50 Cor Cores.";
	next;
	if(select("Exchange:Do not exchange") == 2){
		cutin "ep171_elyumina03",0;
		mes "[ Elyumina ]";
		mes "Are you kidding me? I've been very careful!";
		close3;
	}
	if(countitem(25723) < 50){
		cutin "ep171_elyumina03",0;
		mes "[ Elyumina ]";
		mes "Are you kidding me? You don't have enough Cor Core pieces!";
		close3;
	}
	delitem 25723,50;
	mes "[ Elyumina ]";
	mes "Here, " + .@item_name$[.@s] + "! Take it, don't forget to upgrade it with modules because it will be the best armor you've ever had.";
	getitem .@item_id[.@s],1;
	close3;
}

function	weapon	{
	cutin "ep171_elyumina04",0;
	mes "[ Elyumina ]";	
	mes "OS weapons? I need 1 <ITEM>[Broken Weapon]<INFO>25668</INFO></ITEM> and 50 <ITEM>[Unknown Parts]<INFO>25669</INFO></ITEM>.";
	mes "This is easy for me, I'll fix any of these unfinished weapons.";
	next;
	if(select("Get OS Weapon.:Check all weapon list.") == 2){
		cutin "ep171_elyumina03",0;
		mes "[ Elyumina ]";
		mes "Tsk, even if you pick everything, you can only have one in there, at random!";
		next;
		mes "[ Elyumina ]";
		for(.@i = 0; .@i < getarraysize(.weapon); .@i++){
			.@item_name$ = getitemname(.weapon[.@i]);
			mes "<ITEM>["+.@item_name$+"]<INFO>"+.weapon[.@i]+"</INFO></ITEM>";
		}
		close3;
	} else {
		if(countitem(25668) < 1 || countitem(25669) < 50){
			cutin "ep171_elyumina03",0;
			mes "[ Elyumina ]";
			mes "I told you I need 1 Broken Weapon and 50 Unknown Parts. Open your ears and listen!";
			close3;
		}
		delitem 25668,1;
		delitem 25669,50;
		.@weapon = .weapon[rand(getarraysize(.weapon))];
		cutin "ep171_elyumina04",0;
		mes "[ Elyumina ]";	
		mes "Now, take it. If you need anything else, come back with more broken weapons and unknown parts.";
		getitem .@weapon,1;
		close3;	
	}
}

OnInit:
	setarray .armor$,
	"15376,15377",
	"20933,20934",
	"22196,22197",
	"32207,32208",
	"32209,32210";	
	setarray .weapon,1862,13493,16088,16089,18178,18179,18180,21047,26151,26164,28038,28136,28253,28755,28629,32019;
	cloaknpc(strnpcinfo(0),true);
	end;	
}

sp_cor,106,136,3	script	RS26#illusion_enchant	4_SYS_MSG,{
	disable_items;
	mes "[ RS26 ]";
	mes strcharinfo(0)+".";
	mes "Welcome, Welcome!";
	next;
	switch(select("Explore the devices.:Enchant Illusion Armor.:Enchant Illusion Engine Wing.:Enchant Illusion Leg.:Enchant Illusion Accessory [R]:Enchant Illusion Accessory [L]")){
		case 1:
			mes "^0000FF# I'm the latest hologram technology perfected to show natural responses and gestures. #^000000";
			next;
			mes "[ RS26 ]";
			mes "My technology can only be found in future cities. I am RS26, a Regenschirm robotic machine.";
			npctalk "Rebellion : Oh, that machine is useless without a module.","Rebellion#os_merchant",bc_self;
			next;
			mes "[ RS26 ]";
			mes "If you bring Illusion equipments with strengthening modules, I will improve them as you desire.";
			next;
			mes "[ RS26 ]";
			mes "Since these modules work with the standard equipments, they will not destroy the items. However, the number of upgrades can vary depending of the equipment.";
			next;
			mes "[ RS26 ]";
			mes "Please come back if you need anything else.";
			close;
			
		case 2: .@part = EQI_ARMOR; .@index = 0; setarray .@id,15376,15377; break;
		case 3: .@part = EQI_GARMENT; .@index = 1; setarray .@id,20933,20934; break;
		case 4: .@part = EQI_SHOES; .@index = 3; setarray .@id,22196,22197; break;
		case 5: .@part = EQI_ACC_R; .@index = 2; setarray .@id,32207,32209; break;
		case 6: .@part = EQI_ACC_L; .@index = 2; setarray .@id,32208,32210; break;
	}
	function create_menu;
	.@equip_id = getequipid(.@part);
	.@equip_name$ = getequipname(.@part);
	.@refine = getequiprefinerycnt(.@part);
	for(.@i = 0; .@i < 4; .@i++)
		.@card[.@i] = getequipcardid(.@part,.@i);
	copyarray .@check[0],.@card[0],4;
	if(.@id[0] != .@equip_id && .@id[1] != .@equip_id){
		mes .@id[0] + " " + .@id[1];
		mes "Please make sure you have equipped the item.";
		close;
	}
	if(.@card[1]){
		mes "[ RS26 ]";
		mes "Your equipment doesn't have any slot for any modification modules.";
		end;
	}
	.@list$ = create_menu(.@index,.@part);
	if(.@list$ == ""){
		mes "[ RS26 ]";
		mes "You do not have any modification modules that I can use to enchant your equipment.";
		end;
	}
	mes "[ RS26 ]";
	mes "Select the module you want to insert into your equipment.";
	next;
	explode(.@enchant$,.@list$,":");
	for(.@i = 0; .@i < getarraysize(.@enchant$); .@i += 2)
		.@menu$ += getitemname(atoi(.@enchant$[.@i])) + ":";
	.@s = (select(.@menu$) - 1) * 2;
	mes "[ RS26 ]";
	mes "Are you sure you want to enchant your ^FF0000" +.@equip_name$+"^000000 with ^0000CD" + getitemname(atoi(.@enchant$[.@s])) + "^000000? This process cannot be reversed.";
	next;
	if(select("Wait... Don't:I'm sure. Do it.") == 1){
		mes "[ RS26 ]";
		mes "Okay.";
		end;
	}
	if(!countitem(atoi(.@enchant$[.@s]))){
		mes "[ RS26 ]";
		mes "You do not have the modification modules that I can use to enchant your equipment.";
		end;
	}
	for(.@i = 3; .@i > 0; .@i--){
		if(.@card[.@i] == 0){
			.@augment_slot = .@i;
			break;
		}
	}
	delitem atoi(.@enchant$[.@s]),1;
	.@card[.@augment_slot] = atoi(.@enchant$[.@s+1]);
	if(callfunc("F_IsEquipIDHack", .@part, .@equip_id) || callfunc("F_IsEquipRefineHack", .@part, .@refine) || callfunc("F_IsEquipCardHack", .@part, .@check[0], .@check[1], .@check[2], .@check[3]))
		end;
	delequip .@part;
	getitem2 .@equip_id,1,1,.@refine,0,.@card[0],.@card[1],.@card[2],.@card[3];
	equip .@equip_id;
	mes "[ RS26 ]";
	mes "The process has been completed successfully.";
	end;
	
OnInit:	
	setarray .module$,
	"25670:29527:3,25671:29528:3,25687:29534:2,25688:29535:2,25689:29536:2,25693:29540:1",
	"25670:29527:3,25671:29528:3,25690:29537:2,25691:29538:2,25692:29539:2,25695:29542:1",
	"25672:4742:3,25673:4752:3,25674:4702:3,25675:4732:3,25676:4712:3,25677:4722:3,25678:29529:2,25679:29532:2,25680:4826:1,25681:4881:1,25682:4866:1,25683:4836:1,25696:29543:1,25697:29544:1,25698:29545:1,25699:29546:1",
	"25670:29527:3,25671:29528:3,25684:29531:2,25685:29530:2,25686:29533:2,25694:29541:1",
	"25700:29547,25701:29548,25702:29549,25703:29550,25704:29551,25705:29552";
end;

function	create_menu	{
	.@index = getarg(0);
	.@slot = getarg(1);
	for(.@i = 0; .@i < 4; .@i++)
		.@card[.@i] = getequipcardid(.@slot,.@i);
	explode(.@T$,.module$[.@index],",");
	for(.@i = 0; .@i < getarraysize(.@T$); .@i++){
		.@count = 0;
		explode(.@module$,.@T$[.@i],":");
		.@module = atoi(.@module$[0]);
		.@enchant = atoi(.@module$[1]);
		.@max = atoi(.@module$[2]);
		if(!countitem(.@module))
			continue;
		for(.@j = 0; .@j < 4; .@j++){
			if(.@card[.@j] == .@enchant)
				.@count++;
		}
		if(.@count == .@max)
			continue;
		.@list$ += .@module + ":" + .@enchant + ":";
	}
	if(.@index == 3){
		explode(.@TT$,.module$[4],",");
		for(.@i = 0; .@i < getarraysize(.@TT$); .@i++){
			explode(.@module$,.@TT$[.@i],":");
			.@module = atoi(.@module$[0]);
			.@enchant = atoi(.@module$[1]);
			for(.@j = 0; .@j < 4; .@j++){
				if(.@card[.@j] == .@enchant)
					.@rare++;
			}
			if(!countitem(.@module))
				continue;
			.@legendary$ += .@module + ":" + .@enchant + ":";
			continue;	
		}
	}
	if(.@rare)
		return .@list$;
	else
		return .@list$ + .@legendary$;
}

}
	

sp_cor,136,210,7	script	Gonie#sp_barracks	4_M_GONY,12,12,{
	switch(ep_illusion){
		case 44:
			cutin "16go_01",0;
			mes "[ Gonie ]";
			mes ".....";
			next;
			cloaknpc("Rookie#sp_barracks",false,getcharid(0));
			cloaknpc("Elena Bolkova#sp_barracks",false,getcharid(0));
			cloaknpc("Tess#sp_barracks",false,getcharid(0));
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "Huh, you came here quickly, I heard you were taking a rest.";
			mes "Lazy, please bring the captive.";
			next;
			cloaknpc("Lazy#sp_barracks",false,getcharid(0));
			cloaknpc("Elyumina#sp_barracks",false,getcharid(0));
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Here, that's the captive.";
			mes "It's been a while since we've seen each other Lucky. I missed you!";
			next;
			mes "[ Lazy ]";
			mes "You know I have good taste, Lucky Lucky~ your eyes are great. Just like me, you're great~";
			emotion ET_BIGTHROB,getnpcid(0,"Lazy#sp_barracks");
			npctalk "Lazy : I want to take you out for dinner. My heart is beating so fast.","Lazy#sp_barracks",bc_self;
			npctalk "Lucky : ... let's listen to the whole story first. Let me do the talking.","Rookie#sp_barracks",bc_self;
			next;
			cutin "ep171_elyumina02",0;
			mes "[ Elyumina ]";
			mes "Argh, you idiots! It hurts, don't hold me so tight! Don't you know my body is precious? It's more important than your stupid muscles!";
			emotion ET_HNG,getnpcid(0,"Elyumina#sp_barracks");
			npctalk "Lazy : Now you're speechless. I like that too, it's a good idea.","Lazy#sp_barracks",bc_self;
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes "Okay, excuse me then. Lucky, I'll let you do it.";
			ep_illusion = 45;
			completequest 16358;
			setquest 16359;
			questinfo_refresh();
			close3;
			
		default:
			cutin "16go_01",0;
			mes "[ Gonie ]";
			mes ".....";
			close3;
	}
	end;
		
OnTouch:
	if(ep_illusion == 45){
		cloaknpc("Rookie#sp_barracks",false,getcharid(0));
		cloaknpc("Elena Bolkova#sp_barracks",false,getcharid(0));
		cloaknpc("Tess#sp_barracks",false,getcharid(0));
		cloaknpc("Lazy#sp_barracks",false,getcharid(0));
		cloaknpc("Elyumina#sp_barracks",false,getcharid(0));
	}
end;

OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 44";
end;
}

sp_cor,135,216,5	script	Rookie#sp_barracks	4_M_ROOKIE,{ 
	switch(ep_illusion){
		case 45:
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "Well...";
			mes "(Am I really the one doing the questioning?)";
			npctalk "(Nod nod)","Elena Bolkova#sp_barracks",bc_self;
			npctalk "(Nod nod)","Lazy#sp_barracks",bc_self;
			npctalk "Elyumina : Argh! Let me go! Where are all my smart machines and my dumb subordinates?","Elyumina#sp_barracks",bc_self;
			next;
			cutin "16loo_03",2;
			mes "[ Rookie ]";
			mes "...hey, stop messing around.";
			mes "That's not the attitude we're expecting right now.";
			mes "We've been greatly damaged with the way you've handled things so far.";
			next;
			cutin "ep171_elyumina02",0;
			mes "[ Elyumina ]";
			mes "That's funny! I can't afford to lose just because you guys are hanging around!";
			mes "You're just trying to steal my research and take it all for yourself?!";
			next;
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "Your research, it's an illegal experiment.";
			mes "Did you not think this day would come eventually?";
			npctalk "Lucky : What, no we're not stealing anything.","",bc_self;
			next;
			mes "[ Rookie ]";
			mes "Well, that's okay now. Is your research important to you?";
			mes "If you cooperate with us now, I will preserve your experiments and help you.";
			next;
			mes "[ Rookie ]";
			mes "Obviously, I will do that if it's a legitimate research. So tell me everything about this place and your colleagues.";
			next;
			cutin "ep171_elyumina03",0;
			mes "[ Elyumina ]";
			mes "Colleagues? I don't care what those crazy people are doing.";
			mes "They're not my colleagues, I only use them for my research.";
			next;
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "I see that your name is not on the list that Enterprise gave me.";
			mes "What do you do here? What kind of research do you use these guys for?";
			next;
			cutin "ep171_elyumina01",0;
			mes "[ Elyumina ]";
			mes "Don't you know? I'm the best machine researcher in Schwarzwald.";
			mes "You've already seen one of my machine I made from my technology.";
			next;
			cutin "16loo_03",2;
			mes "[ Rookie ]";
			mes "... I haven't seen it.";
			npctalk "Nothing?","Elena Bolkova#sp_barracks",bc_self;
			npctalk "Nope, can't find it.","Lazy#sp_barracks",bc_self;
			next;
			cutin "ep171_elyumina01",0;
			mes "[ Elyumina ]";
			mes "You guys don't understand, these machines are my children.";
			mes "If I did a little more work, I could keep the human spirit almost intact on my machines.";
			next;
			cutin "ep171_elyumina04",0;
			mes "[ Elyumina ]";
			mes "I was able to fill my hard work in my beautiful machines, but instead I was only given poor and weak bodies.";
			next;
			cutin "ep171_elyumina03",0;
			mes "[ Elyumina ]";
			mes "Do you understand? My work is amazing and you can't comprehend it.";
			mes "Everyone here is too stupid to understand it.";
			npctalk "Are you weak? Because I'm strong.","Elena Bolkova#sp_barracks",bc_self;
			npctalk "I'm strong too.","Lazy#sp_barracks",bc_self;
			npctalk "Bor... if you are, then you are.","",bc_self;
			next;
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "Bor... Borseev or Berner...? Do you know them?";
			next;
			cutin "ep171_elyumina03",0;
			mes "[ Elyumina ]";
			mes "Well, these are both names. I don't care much for names.";
			next;
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "No, you should be interested. I'll have to teach you how things are working out for you.";
			mes "Listen very carefully. You have two options...";
			next;
			cutin "16loo_02",2;
			mes "[ Rookie ]";
			mes "First. You keep sticking to your story.";
			mes "You refuse to tell us whether or not your research was illegal, and you don't give us information about your friends.";
			mes "The result of that would lead to... death penalty. That's not the future I was hoping for.";
			npctalk "Elyumina : ....","Elyumina#sp_barracks",bc_self;
			next;
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "Second, you think about your future.";
			mes "You give up information about your colleagues, and you get to continue your research to some extent.";
			next;
			cutin "16loo_03",2;
			mes "[ Rookie ]";
			mes "Of course you'll have to pay for what you've done, but in the end you'll get to continue what you want to do.";
			next;
			cutin "ep171_elyumina03",0;
			mes "[ Elyumina ]";
			mes "....";
			next;
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "We will also lose if you choose the first option. But you said you do great research? Then we'd be happy to work with you.";
			mes "I want to judge you fairly.";
			next;
			mes "[ Elyumina ]";
			mes "I... I don't really know what the others were doing.";
			mes "... Is the deal still valid?";
			next;
			cutin "16loo_02",2;
			mes "[ Rookie ]";
			mes "Well... of course. But only if you cooperate sincerely, then I will look the other way.";
			mes "So let's have a deep talk, I'm sending you back to Lazy.";
			npctalk "Lazy : So, are you going to do good, oh great researcher?","Lazy#sp_barracks",bc_self;
			next;
			cutin "16lei_03",2;
			mes "[ Lazy ]";
			mes ".....";		
			cloaknpc("Elyumina#sp_barracks",true,getcharid(0));
			cloaknpc("Elyumina#sp_barracks2",false,getcharid(0));
			npctalk "Lucky : ...so it's like that. I see...","",bc_self;
			next;
			mes "[ Lazy ]";
			mes "...";
			mes "There, we've said everything. Hot Captain?";
			next;
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "... is that what you're calling me?";
			npctalk "Elyumina : ...yes. But there's also....","Elyumina#sp_barracks2",bc_self;
			next;
			cutin "16lei_02",2;
			mes "[ Lazy ]";
			mes "How else would you be called?";
			mes "Aren't you the only captain here?";
			mes "Anyway, I was going to peek at the story myself. It sounds interesting.";
			next;
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "Ah... well. Okay.";
			mes "Lucky is doing great. What do you think they're talking about now?";
			npctalk "Lucky : ...good. So here it is...","",bc_self;
			next;
			cutin "16lei_01",2;
			mes "[ Lazy ]";
			mes "Of course I wouldn't know. You didn't give me a chance to do the interrogation, did you?";
			mes "But I know Lucky will do great.";
			npctalk "Elyumina : ...okay? Keep your promise. So again...","Elyumina#sp_barracks2",bc_self;
			next;
			cutin "162elena_01",2;
			mes "[ Elena Bolkova ]";
			mes "Hmm...";
			npctalk "Lucky : Alright, good work! Now we don't have to worry about eliminating you.","",bc_self;
			next;
			cutin "16loo_01",2;
			mes "[ Rookie ]";
			mes "What are you two talking about?";
			mes "Anyway, I've heard everything I needed to know for now.";
			mes "They call themselves the ^0000FFIllusion^000000. I also confirmed she was a researcher at the ^0000FFRegenschirm laboratory.^000000";
			next;
			mes "[ Rookie ]";
			mes "Elyumina doesn't seem to know the details.";
			mes "She hasn't been in contact with the Enterprise, that's why she wasn't on the list.";
			npctalk "Lazy : Looks like a subcontractor","Lazy#sp_barracks",bc_self;
			npctalk "Elyumina : Subcontracting for a researcher!","Elyumina#sp_barracks2",bc_self;
			next;
			mes "[ Rookie ]";
			mes "And beyond this area... There's a hidden mansion that belongs to ^0000FFVarmundt.^000000";
			mes "After they discovered this place, they made a group to gather knowledge and run this as a facility.";
			next;
			mes "[ Rookie ]";
			mes "Elyumina doesn't know what's inside the mansion.";
			mes "After the others escaped this place and went inside the mansion, some stayed here to keep the research materials, even after they chose the site.";
			next;
			cutin "16loo_02",2;
			mes "[ Rookie ]";
			mes "You can go to the <NAVI>[tunnels]<INFO>sp_cor,255,285,0,000,0</INFO></NAVI> at the right end of the fence.";
			mes "We better check it ourselves!";
			ep_illusion = 46;
			completequest 16359;
			setquest 16360;
			questinfo_refresh();
			close2;
			cutin "",255;
			cloaknpc("Rookie#sp_barracks",true,getcharid(0));
			cloaknpc("Elena Bolkova#sp_barracks",true,getcharid(0));
			cloaknpc("Tess#sp_barracks",true,getcharid(0));
			cloaknpc("Lazy#sp_barracks",true,getcharid(0));
			cloaknpc("Elyumina#sp_barracks2",true,getcharid(0));
	}
	end;

OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 45";
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,141,215,3	script	Elena Bolkova#sp_barracks	4_F_ELENA,{
	if(ep_illusion == 45){
		cutin "162elena_01",2;
		mes "[ Elena Bolkova ]";
		mes "I'm busy focusing with my eyes!!";
		close3;
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,138,219,3	script	Tess#sp_barracks	4_M_PHILOFONTES,{ 
	if(ep_illusion == 45){
		cutin "ep16_tes01",2;
		mes "[ Tess ]";
		mes "It's an important interrogation, we should let the government know as well, no? I don't know what to say later.";
		npctalk "Lazy : You're too rigid, too scrupulous~","Lazy#sp_barracks",bc_self;
		close3;
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,141,211,1	script	Lazy#sp_barracks	4_M_LAZY,{
	if(ep_illusion == 45){
		cutin "16lei_03",2;
		mes "[ Lazy ]";
		mes "It's time for Lucky to show his skills. Ya, what are you expecting?";
		close3;
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,140,213,3	script	Elyumina#sp_barracks	4_EP17_ELYUMINA,{
	if(ep_illusion == 45){
		cutin "ep171_elyumina03",0;
		mes "[ Elyumina ]";
		mes "...";
		next;
		cutin "ep171_elyumina02",0;
		mes "[ Elyumina ]";
		mes "Don't talk to me!";
		close3;
	}
	end;
	
OnInit:
	cloaknpc(strnpcinfo(0),true);
end;
}

sp_cor,136,217,3	duplicate(dummynpc)	Elyumina#sp_barracks2	4_EP17_ELYUMINA
sp_cor,254,284,7	duplicate(dummynpc)	Gonie#sp_cor_tunnel	4_M_GONY
sp_cor,259,278,1	duplicate(dummynpc)	Elyumina#sp_cor_tunnel	4_EP17_ELYUMINA
sp_cor,260,276,3	duplicate(dummynpc)	Elena Bolkova#sp_cor_tunnel	4_F_ELENA

sp_cor,155,94,3	script	Yuslan#171_dailies	4_M_GUNSLINGER3,{
	switch(checkquest(7868,PLAYTIME)){
		case -1:
			break;
			
		case 0: case 1:
			mes "[ Yuslan ]";
			mes "Woah, you worked hard today.";
			mes "Special forces are on the lookout already, but they haven't found a laboratory...";
			next;
			mes "[ Yuslan ]";
			mes "How do the Heart Hunters come back so fast?";
			mes "I think we should fight again soon, but for now let's take a break.";
			end;
			
		case 2:
			mes "[ Yuslan ]";
			mes "Huh~ Did you rest well?";
			mes "Let's prepare for a Heart Hunter hunt.";
			mes "When you're ready, let's go again.";
			erasequest 7868;
			end;
	}
	switch(checkquest(7867,HUNTING)){
		case -1:
			break;
			
		case 1:
			mes "[ Yuslan ]";
			mes "Please handle 15 ^0000FFHeart Hunter Bellares and  Heart Hunter Sanares.^000000";
			mes "I want to get battle information.";
			next;
			mes "[ Yuslan ]";
			mes "You know the location, right?";
			mes "You can follow the track from there.";
			end;
			
		case 2:
			mes "[ Yuslan ]";
			mes "These guys were stronger than expected.";
			mes "It seems like their equipment or abilities have increased in various ways.";
			next;
			mes "[ Yuslan ]";
			mes "I wonder if those were strengthened through the experimentations in this lab?";
			mes "They've become so strong now, I don't trust these people...";
			next;
			mes "[ Yuslan ]";
			mes "Thank you very much for today's work.";
			mes "Take a rest for now.";
			setquest 7868;
			erasequest 7867;
			getexp 200000,200000;
			getitem 25669,5;
			getitem 25723,1;
			close2;
			npctalk "I need a break...","",bc_self;
			end;
	}
	mes "[ Yuslan ]";
	mes "The Heart Hunters and the Bellare are not like those we've met before.";
	mes "They are hard to deal with.";
	next;
	mes "[ Yuslan ]";
	mes "Because of that, the Erst special troops are hiding in the battlefield to advance further.";
	mes "We have to deal with those guys, sometimes it's hard.";
	next;
	if(select("Let's do it.:That sounds like trouble.") == 2){
		mes "[ Yuslan ]";
		mes "It will  be. Huh.";
		mes "The adventurer should take a break.";
		mes "Your body must be tired.";
		close;
	}
	mes "[ Yuslan ]";
	mes "That's good to hear.";
	mes "Will you able to deal with Heart Hunter Bellares and Sanares properly?";
	mes "Please hunt down 15 of each Heart Hunters.";
	next;
	mes "[ Yuslan ]";
	mes "I want to gather more combat data if possible.";
	mes "I would really appreciate it.";
	setquest 7867;
	close2;
	npctalk "I need a break...","",bc_self;
	end;
	
OnInit:
	questinfo(QTYPE_DAILYQUEST,QMARK_YELLOW,"ep_illusion >= 35 && checkquest(7868,PLAYTIME) == -1 && checkquest(7867,HUNTING) == -1");
	questinfo(QTYPE_DAILYQUEST,QMARK_YELLOW,"ep_illusion >= 35 && checkquest(7868,PLAYTIME) == 2 && checkquest(7867,HUNTING) == -1");
	questinfo(QTYPE_DAILYQUEST,QMARK_YELLOW,"checkquest(7867,HUNTING) == 2");
end;
}

sp_cor,246,97,3	script	Farm Worker#illusion_daily	1_M_03,{
	if(ep_illusion < 47){
		mes "[ Farm Worker ]";
		mes "I'm busy and I don't think people in the city would appreciate the smell of fertilizer. There are lot of people in the research facility, but let's go anyway.";
		close;
	}
	switch(checkquest(16365,PLAYTIME)){
		case -1:
			break;
			
		case 0: case 1:
			mes "[ Farm Worker ]";
			mes "The crops are still fresh. If you tend them now, it won't help.";
			mes "They are very sensitive.";
			next;
			mes "[ Farm Worker ]";
			mes "Please come back after dawn.";
			close;
			
		case 2:
			erasequest 16365;
			break;
	}
	switch(checkquest(16364)){
		case -1:
			mes "[ Farm Worker ]";
			mes "We were in charge of raising crops here. We are proud of our self-sufficient farms.";
			next;
			mes "[ Farm Worker ]";
			mes "But recently, a lot of people want to transfer out, so we don't have enough manpower. Could you help us take care of the crops.";
			next;
			if(select("Help.:Don't help.") == 2){
				mes "[ Farm Worker ]";
				mes "Ever since our elders passed, things have been a bit chaotic...";
				next;
				mes "[ Farm Worker ]";
				mes "What happened?? Actually it' wasn't 'a bit' chaotic, it was a lot...";
				close;
			}
			mes "[ Farm Worker ]";
			mes "Thank you! If you go to the farm, I've got grapes, beans and pumpkins for you to take care of.";
			next;
			.@grapes = rand(3);
			.@beans = rand(3);
			.@pumpkins = rand(3);
			explode(.@grapes$,.grapes$[.@grapes],",");
			explode(.@beans$,.beans$[.@beans],",");
			explode(.@pumpkins$,.pumpkins$[.@pumpkins],",");
			setquest atoi(.@grapes$[0]);
			setquest atoi(.@beans$[0]);
			setquest atoi(.@pumpkins$[0]);
			setquest 16364;
			completequest 16364;
			setquest 16366;
			mes "[ Farm Worker ]";
			mes "You still need to " +.@grapes$[1]+ " on the grape vines, " + .@beans$[1] + " on the bean plants, " + .@pumpkins$[1] + " on the pumpkins.";
			farm_daily = 0;
			farm_status$ = .@grapes+":"+.@beans+":"+.@pumpkins;
			questinfo_refresh();
			end;
		
		default:
			break;
	}
	switch(checkquest(16366)){
		case -1:
			mes "[ Farm Worker ]";
			mes "Time is of the essence and the crops are not looking well... Will you help me on the field today?";
			next;
			mes "[ Farm Worker ]";
			mes "Since you are here, I might be able to do more work and take care of everything.";
			next;
			if(select("Help.:Don't help.") == 2){
				mes "[ Farm Worker ]";
				mes "Ever since our elders passed, things have been a bit chaotic...";
				next;
				mes "[ Farm Worker ]";
				mes "What happened?? Actually it' wasn't 'a bit' chaotic, it was a lot...";
				close;
			}
			mes "[ Farm Worker ]";
			mes "Thank you! If you go to the farm, I've got grapes, beans and pumpkins for you to take care of.";
			next;
			.@grapes = rand(3);
			.@beans = rand(3);
			.@pumpkins = rand(3);
			explode(.@grapes$,.grapes$[.@grapes],",");
			explode(.@beans$,.beans$[.@beans],",");
			explode(.@pumpkins$,.pumpkins$[.@pumpkins],",");
			setquest atoi(.@grapes$[0]);
			setquest atoi(.@beans$[0]);
			setquest atoi(.@pumpkins$[0]);
			setquest 16366;
			mes "[ Farm Worker ]";
			mes "You still need to " +.@grapes$[1]+ " on the grape vines, " + .@beans$[1] + " on the bean plants, " + .@pumpkins$[1] + " on the pumpkins.";
			farm_daily = 0;
			farm_status$ = .@grapes+":"+.@beans+":"+.@pumpkins;
			questinfo_refresh();
			end;			
		
		case 1:
			if(farm_daily < 3){
				explode(.@T$,farm_status$,":");
				explode(.@grapes$,.grapes$[atoi(.@T$[0])],",");
				explode(.@beans$,.beans$[atoi(.@T$[1])],",");
				explode(.@pumpkins$,.pumpkins$[atoi(.@T$[2])],",");
				mes "[ Farm Worker ]";
				mes "You still need to " +.@grapes$[1]+ " on the grape vines, " + .@beans$[1] + " on the bean plants, " + .@pumpkins$[1] + " on the pumpkins.";
				next;
				mes "[ Farm Worker ]";
				mes "Please go and check it out.";
				end;
			}
			mes "[ Farm Worker ]";
			mes "You did it! You seem more like a farmer then an adventurer.";
			next;
			mes "[ Farm Worker ]";
			mes "We can't give you much, but I see that mercenaries have been collecting these. Would you like one as well?";
			next;
			mes "[ Farm Worker ]";
			mes "Thank you for taking core of the crops. I hope to see you everyday.";
			setquest 16365;
			erasequest 16366;
			farm_daily = 0;
			farm_status$ = "";
			getitem 25723,1;
			getitem 25669,5;
			end;
	}
	end;
		
OnInit:
	questinfo(QTYPE_DAILYQUEST,QMARK_YELLOW,"ep_illusion >= 47 && checkquest(16364) != 2");
	questinfo(QTYPE_DAILYQUEST,QMARK_YELLOW,"ep_illusion >= 47 && checkquest(16366) == -1 && checkquest(16365,PLAYTIME) == 2");
	questinfo(QTYPE_DAILYQUEST,QMARK_YELLOW,"ep_illusion >= 47 && checkquest(16366) == -1 && checkquest(16365,PLAYTIME) == -1");
	questinfo(QTYPE_DAILYQUEST,QMARK_YELLOW,"farm_daily == 3");
	setarray .grapes$,"16367,catch aphids","16368,add some fertilizer","16369,remove the weeds";
	setarray .beans$,"16370,catch aphids","16371,add some fertilizer","16372,remove the weeds";
	setarray .pumpkins$,"16373,catch aphids","16374,add some fertilizer","16375,remove the weeds";
	end;
}

sp_cor,160,135,0	script	Bean Plants#daily_00	4_ENERGY_WHITE,{
	if(checkquest(16366) != 1){
		mes "[ Bean Plants ]";
		mes "The bean plants seem to be growing well.";
		close;
	}
	for(.@i = 0; .@i < getarraysize(.quest_id); .@i++){
		if(checkquest(.quest_id[.@i]) == 1){
			.@quest_id = .quest_id[.@i];
			.@answer = .@i;
			break;
		}
	}
	if(.@quest_id == 0){
		mes "[ Bean Plants ]";
		mes "Somehow the beans looks a lot more lively now.";
		close;
	}
	mes "[ Bean Plants ]";
	mes "The bean plants look like they're lacking something.";
	next;
	.@s = select("Catch aphids:Give fertilizer:Pull weeds.") - 1;
	switch(.@s){
		case 1:
			mes "[ Bean Plants ]";
			mes "I caught the aphids on the bean stalks.";
			next;
			break;
			
		case 2:
			mes "[ Bean Plants ]";
			mes "I put fertilizer on the bean plants.";
			next;
			break;
			
		case 3:
			mes "[ Bean Plants ]";
			mes "I pulled out the weeds around the bean plants.";
			next;
			break;
	}
	if(.@s == .@answer){
		mes "[ Bean Plants ]";
		mes "Nice, the beans are starting to look better!";
		specialeffect 325;
		erasequest .@quest_id;
		farm_daily += 1;
		questinfo_refresh();
		if(farm_daily == 3){
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "I tended to the crops. Not let's go back to the farm worker.";
			questinfo_refresh();
			end;
		}
	} else {
		mes "[ Bean Plants ]";
		mes "Somehow, it looks like it still needs something else?";
	}
	end;

OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"checkquest(16370) == 1 || checkquest(16371) == 1 || checkquest(16372) == 1");
	setarray .quest_id,16370,16371,16372;
	end;
}

sp_cor,240,87,0	script	Pumpkin Plants#daily_00	4_ENERGY_WHITE,{
	if(checkquest(16366) != 1){
		mes "[ Pumpkin Plants ]";
		mes "The pumpkin leaves are sprouting lively on the stem.";
		close;
	}
	for(.@i = 0; .@i < getarraysize(.quest_id); .@i++){
		if(checkquest(.quest_id[.@i]) == 1){
			.@quest_id = .quest_id[.@i];
			.@answer = .@i;
			break;
		}
	}
	if(.@quest_id == 0){
		mes "[ Pumpkin Plants ]";
		mes "Somehow the pumpkins looks a lot more lively now.";
		close;
	}
	mes "[ Pumpkin Plants ]";
	mes "The Pumpkin look like they're lacking something.";
	next;
	.@s = select("Catch aphids:Give fertilizer:Pull weeds.") - 1;
	switch(.@s){
		case 1:
			mes "[ Pumpkin Plants ]";
			mes "I caught the aphids on the pumpkins stalks.";
			next;
			break;
			
		case 2:
			mes "[ Pumpkin Plants ]";
			mes "I added fertilizer on the Pumpkin's soil.";
			next;
			break;
			
		case 3:
			mes "[ Pumpkin Plants ]";
			mes "I pulled out the weeds around the pumpkin stalks.";
			next;
			break;
	}
	if(.@s == .@answer){
		mes "[ Pumpkin Plants ]";
		mes "Nice, the pumpkins are starting to look better!";
		specialeffect 325;
		erasequest .@quest_id;
		farm_daily += 1;
		questinfo_refresh();
		if(farm_daily == 3){
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "I tended to the crops. Not let's go back to the farm worker.";
			questinfo_refresh();
			end;
		}
	} else {
		mes "[ Pumpkin Plants ]";
		mes "Somehow, it looks like it still needs something else?";
	}
	end;
	
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"checkquest(16373) == 1 || checkquest(16374) == 1 || checkquest(16375) == 1");
	setarray .quest_id,16373,16374,16375;
	end;
}

sp_cor,246,85,0	script	Grape Plants#daily_00	4_ENERGY_WHITE,{
	if(checkquest(16366) != 1){
		mes "[ Grape Plants ]";
		mes "There are small blue grapes on the vine.";
		close;
	}
	for(.@i = 0; .@i < getarraysize(.quest_id); .@i++){
		if(checkquest(.quest_id[.@i]) == 1){
			.@quest_id = .quest_id[.@i];
			.@answer = .@i;
			break;
		}
	}
	if(.@quest_id == 0){
		mes "[ Grape Plants ]";
		mes "The grapevines are regaining it's vitality.";
		close;
	}
	mes "[ Grape Plants ]";
	mes "The grapevines look like they're missing something.";
	next;
	.@s = select("Catch aphids:Give fertilizer:Pull weeds.") - 1;
	switch(.@s){
		case 1:
			mes "[ Grape Plants ]";
			mes "I caught the aphids on the grapevine stem.";
			next;
			break;
			
		case 2:
			mes "[ Grape Plants ]";
			mes "I added fertilizer on the soil of the grapevine.";
			next;
			break;
			
		case 3:
			mes "[ Grape Plants ]";
			mes "I pulled out the weeds around the grapevines.";
			next;
			break;
	}
	if(.@s == .@answer){
		mes "[ Grape Plants ]";
		mes "I can feel it, the grapes are pleased!";
		specialeffect 325;
		erasequest .@quest_id;
		farm_daily += 1;
		questinfo_refresh();
		if(farm_daily == 3){
			next;
			mes "[ "+strcharinfo(0)+" ]";
			mes "I tended to the crops. Not let's go back to the farm worker.";
			questinfo_refresh();
			end;
		}
	} else {
		mes "[ Grape Plants ]";
		mes "Somehow, it looks like it still needs something else?";
	}
	end;
		
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"checkquest(16367) == 1 || checkquest(16368) == 1 || checkquest(16369) == 1");
	setarray .quest_id,16367,16368,16369;
end;
}

//= Other/Warp
pub_cat,51,29,1	script	Tired Guest#171_pub	4_M_REPAIR,{
	npctalk "I just want to drink two glasses. But if I drink two, I'll want to order a third one.","",bc_self;
	end;
}

pub_cat,52,32,5	script	Bartender#171_pub_5	1_ETC_01,{
	npctalk "This place is for busy guests to have a light drink. Enjoy yourself.","",bc_self;
	end;
}

pub_cat,55,33,3	script	Sales Manager#171_pub	4_CAT_SAILOR4,{
	emotion ET_MONEY;
	end;
}

pub_cat,61,46,5	script	Employee#171_pub	4_M_HUMAN_01,{
	npctalk "Welcome! Sit at your convenience!","",bc_self;
	end;
}

pub_cat,74,73,3	script	Vice President#171_pub	4_CAT,{
	emotion ET_SCRATCH;
	end;
}

pub_cat,67,73,3	script	Bullet President#171_pub	4_CAT_REST,{
	emotion ET_SLEEPY;
	end;
}

pub_cat,84,66,3	script	Wilde#171_pub	1_M_SIGNROGUE,2,2,{
	switch(ep_illusion){
		case 13:
			mes "[ Wilde ]";
			mes "Hey! What's going on here?";
			npctalk "Hey! What's going on here?","",bc_self;
			next;
			mes "[ Wilde ]";
			mes "What? Are you the guy they're waiting for? You see the room behind me? Go ahead and go in.";
			end;
		case 14:
		case 15:
			mes "[ Wilde ]";
			mes "Are you going in? I'm pretty loud so I'll go in later.";
			end;
			
		default:
			break;
	}
	if(ep_illusion < 13){
		mes "[ Wilde ]";
		mes "What? Is this your first time here?";
		mes "The drinks come from over there.";
		next;
		mes "[ Wilde ]";
		mes "This place is for adults only.";
		close;
	} else {
		mes "[ Wilde ]";
		mes "Wait nobody is back there now, are you waiting for someone?";
		close;
	}
	
OnTouch:
	switch(ep_illusion){
		case 13:
			mes "[ Wilde ]";
			mes "Hey! What's going on here?";
			npctalk "Hey! What's going on here?","",bc_self;
			next;
			mes "[ Wilde ]";
			mes "What? Are you the guy they're waiting for? You see the room behind me? Go ahead and go in.";
			end;
		case 14:
		case 15:
			mes "[ Wilde ]";
			mes "Are you going in? I'm pretty loud so I'll go in later.";
			end;
			
		default:
			break;
	}
	if(ep_illusion > 16)
		npctalk "Hello!","",bc_self;
	end;
	
OnInit:
	questinfo(QTYPE_QUEST,QMARK_YELLOW,"ep_illusion == 13");
	end;
}

pub_cat,73,75,3	script	Bartender#171_pub_1	1_F_PUBGIRL,{
	npctalk "Would you like to place an order?","",bc_self;
	end;
}

pub_cat,64,82,5	script	Bartender#171_pub_2	4_M_CASMAN1,{
	npctalk "How are you feeling today? I can recommend you a drink depending of your mood.","",bc_self;
	end;
}

pub_cat,62,82,5	script	Bartender#171_pub_3	4_M_MANAGER,{
	npctalk "Don't worry about telling me anything you're thinking about, I'll keep it a secret.","",bc_self;
	end;
}

pub_cat,28,71,5	script	Bartender#171_pub_4	1_M_PUBMASTER,{
	npctalk "This place is reserved for those who want to have a quiet talk.","",bc_self;
	end;
}

pub_cat,56,58,3	script	Guest#171_pub_1	4_TOWER_04,{
	npctalk "I drank too much today... Why not come and join us?","",bc_self;
	end;
}

pub_cat,55,60,5	script	Guest#171_pub_2	4_TOWER_02,{
	setpcblock PCBLOCK_ALL,true;
	npctalk "What would you write on this travel log? That the boss is nice but drunk?","",bc_self;
	sleep2 2000;
	npctalk "Oh, that's wrong. I'd write the boss passed out and gave drinking gifts. Uh... does that sound strange too?","Guest#171_pub_1",bc_self;
	setpcblock PCBLOCK_ALL,false;
	end;
}

pub_cat,75,58,3	script	Guest#171_pub_3	4_TOWER_02,{
	npctalk "Even if she's a little noisy sometimes, I understand. I joked with the factory manager today and got fired.","",bc_self;
	end;
}

pub_cat,75,58,3	script	Guest#171_pub_4	4_M_ALCHE_A,{
	setpcblock PCBLOCK_ALL,true;
	npctalk "Hah ah!! Why did I say that?! Because of my mouth!! My mom is always nice! To me!!","",bc_self;
	sleep2 2000;
	npctalk "It's okay. I didn't screw up. Even though I got fired, I'm good with my hands.","Guest#171_pub_3",bc_self;
	setpcblock PCBLOCK_ALL,false;
	end;
}

pub_cat,64,66,1	script	Guest#171_pub_5	4_F_MONK,{
	npctalk "Huh, it's so hard to match with a young guy.","",bc_self;
	end;
}

pub_cat,63,69,5	script	Guest#171_pub_6	4_M_ROGUE,{
	setpcblock PCBLOCK_ALL,true;
	//=俺は風神だ！！　ヤー！！！
	npctalk "I'm the God of Wind!! Hya!!","",bc_self;
	specialeffect 775;
	sleep2 2000;
	npctalk "Go spin again!","Guest#171_pub_5",bc_self;
	setpcblock PCBLOCK_ALL,false;
	end;
}

pub_cat,53,69,5	script	Guest#171_pub_7	4_M_RACHMAN1,{
	npctalk "When should I try to sell this stuffs?","",bc_self;
	end;
}

pub_cat,55,69,5	script	Guest#171_pub_8	4_M_REPAIR,{
	setpcblock PCBLOCK_ALL,true;
	npctalk "Goodnight, I'll be fine wherever I go.","",bc_self;
	sleep2 2000;
	npctalk "I'm sorry. You know how I feel about this but. I'm glad for you though.","Guest#171_pub_7",bc_self;
	sleep2 2000;
	npctalk "I will miss you.","Guest#171_pub_9",bc_self;
	setpcblock PCBLOCK_ALL,false;
	end;
}

pub_cat,57,67,3	script	Guest#171_pub_9	4_F_CAPEGIRL,{
	npctalk "I moved to this city, but I'm in a bad mood because my friends are leaving.","",bc_self;
	end;
}

pub_cat,70,71,7	script	Guest#171_pub_10	4_M_EINMAN,{
	npctalk "The Vice President is about to fly!","",bc_self;
	end;
}

pub_cat,70,72,7	script	Guest#171_pub_11	4_M_EINMAN2,{
	npctalk "Oh Vice President!! Please accept my greetings.","",bc_self;
	end;
}

pub_cat,64,79,1	script	Guest#171_pub_12	4_F_EINWOMAN,{
	setpcblock PCBLOCK_ALL,true;
	npctalk "I'm going to drink all the alcohol here today!","",bc_self;
	sleep2 2000;
	npctalk "Okay! Challenge accepted.","Guest#171_pub_13",bc_self;
	setpcblock PCBLOCK_ALL,false;
	end;
}

pub_cat,62,79,7	script	Guest#171_pub_13	4_F_JOB_BLACKSMITH,{
	npctalk "Hey, have you seen my cart today?","",bc_self;
	end;
}

pub_cat,39,95,1	script	Guest#171_pub_14	4_M_SIT_NOVICE,{
	npctalk "I earned a good amount of money today!","",bc_self;
	end;
}

pub_cat,41,98,3	script	Guest#171_pub_15	4_M_DEWGIRL,{
	npctalk "I have to go now.","",bc_self;
	sleep2 2000;
	npctalk "Already? Why don't you stay a little bit longer? I just ordered a stew, what do you say?","Guest#171_pub_14",bc_self;
	sleep2 2000;
	npctalk "I'll have some soup, but I can't stay anymore.","",bc_self;
	end;
}

pub_cat,45,96,1	script	Guest#171_pub_16	4_F_04,{
	npctalk "Shouldn't you awake by now? Hey, wake up!","",bc_self;
	sleep2 2000;
	npctalk "Huh!!! Waaaaa!!","Guest#171_pub_17",bc_self;
	sleep2 2000;
	npctalk "Everytime. If you only drink alcohol, you'll become a dog. Tsk tsk.","Guest#171_pub_18",bc_self;
	end;
}

pub_cat,47,95,3	script	Guest#171_pub_17	4_M_LYINGDOG,{
	npctalk "Huh!! Huwah!","",bc_self;
	end;
}

pub_cat,45,99,5	script	Guest#171_pub_18	4_M_LGTMAN,{
	npctalk "I won't go near you anymore. You're acting very weird!","",bc_self;
	sleep2 2000;
	npctalk "I'm going to stay here until the day ends, what's this? Everyone is already asleep?","",bc_self;
	end;
}

pub_cat,47,100,5	script	Guest#171_pub_19	4_M_LIEMAN,{
	npctalk "Ugh, I don't feel good.","",bc_self;
	end;
}

lighthalzen,43,271,5	script	Rekenber Guard#171_light_1	4_M_LGTGUARD,{ end; }
lighthalzen,46,271,5	script	Rekenber Guard#171_light_2	4_M_LGTGUARD,{ end; }

sp_cor,106,103,3	script	#cor_doppel	8_DOPPEL,1,1,{
OnTouch:
	setpcblock PCBLOCK_ALL, true;
	npctalk "c.a....a...","",bc_self;
	sleep2 1000;
	classchange HIDDEN_WARP_NPC,"",bc_self;
	sleep2 500;
	setpcblock PCBLOCK_ALL, false;
end;
}

sp_cor,218,134,3	script	Dog#cor_os	4_DOG01,{
	emotion ET_BIGTHROB;
	npctalk "Meow~!","",bc_self;
	end;
}

sp_cor,63,144,3	script	Worker#cor_other_00	1_M_SIGNMONK,{
	mes "[ Worker ]";
	mes "I can't go now, but when I'm old enough, I'll go and work. I don't have time to play.";
	close;
}

sp_cor,69,192,1	script	Worker#cor_other_01	4_M_ROGUE,{
	npctalk "Huh, I'm really tired of this. If it weren't for the money, I wouldn't be doing it.","",bc_self;
	end;
}

sp_cor,69,194,1	script	Worker#cor_other_02	4_F_CHNWOMAN,{
	setpcblock PCBLOCK_ALL, true;
	npctalk "But what is this building for, really?","",bc_self;
	sleep2 1500;
	npctalk "I don't know.","Worker#cor_other_01",bc_self;
	sleep2 1500;
	npctalk "Are we... going to be okay...?","",bc_self;
	setpcblock PCBLOCK_ALL, false;
	end;
}

sp_cor,62,258,3	script	Worker#cor_other_03	1_F_GYPSY,{
	npctalk "I've been working here for the whole year, but I still don't exactly know what I'm doing.","",bc_self;
	end;
}

sp_cor,70,263,5	script	Worker#cor_other_04	4_M_02,{
	switch(finding_patrick){
		case 4:
			mes "[ Worker ]";
			mes "Don't put food waste in there. It will smell.";
			npctalk "Be careful here.","",bc_self;
			next;
			mes "[ Worker ]";
			mes "Oh... did you come to pick up the materials? I have arranged it as best as I could, but I cann't classify it because I don't know what it is.";
			next;
			select("Can I have a look?");
			mes "[ Worker ]";
			mes "Of course. But do you really think there's something of value in there? They would have taken it before leaving.";
			next;
			select("Is all the garbage incinerated here?");
			mes "[ Worker ]";
			mes "Well, to be accurate, this is not an incinerator, it's just a temporary loading station that collects garbage before they are incinerated. The actual incinerator is farther away.";
			next;
			select("How do the researchers handle the garbage?");
			mes "[ Worker ]";
			mes "We collect the garbage from each room and then nprocess it. Well, usually that's what we do for neat people. They don't say much.";
			npctalk "I can't understand how people who are so smart can be so dirty and messy.";
			next;
			mes "[ Worker ]";
			mes "How can they call themselves real people if they can't even throw their trash in proper places. Maybe there piles left behind in the mountains.";
			next;
			select("Do you also burn the contaminated materials?");
			mes "[ Worker ]";
			mes "That's not it. I only categorize large materials or technical equipments.";
			next;
			mes "[ Worker ]";
			mes "There are separate waste dumps that collect only contaminated materials that can't be burned. We're often in contact with one another.";
			next;
			select("Did you go there yourself?");
			mes "[ Worker ]";
			mes "No, I don't actually go there myself. There's a specialized department in charge of that. They use the rails with the wagons because the materials are toxic or too big.";
			next;
			mes "[ Worker ]";
			mes "Huh... you know... the garbage... is an important job...";
			npctalk "No that's not it. People should live with good thoughts.","",bc_self;
			next;
			select("Do you know Patrick Kaufman?");
			next;
			mes "[ Worker ]";
			mes "Patrick Kaufman...? No, but you mean Patrick Young, right?";
			next;
			select("No. But I'm heading to the waste site.");
			mes "[ Worker ]";
			mes "Oh, you're going to the <NAVI>[waste site]<INFO>sp_rudus,227,351,0,101,0</INFO></NAVI>? Huh, good luck. I think you'll need it.";
			finding_patrick = 5;
			completequest 17023;
			setquest 17024;
			end;
			
		case 5:
			mes "[ Worker ]";
			mes "Oh, you're going to the <NAVI>[waste site]<INFO>sp_rudus,227,351,0,101,0</INFO></NAVI>? Huh, good luck. I think you'll need it.";
			end;
	}
	mes "[ Worker ]";
	mes "What should I do next? I guess I can't keep working here.";
	close;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"finding_patrick == 4";
end;
}

sp_cor,138,265,5	script	Worker#cor_other_05	4_F_SHABBY,{
	npctalk "There were trains on this track and I had to control them. Now the gunmen came and asked me how it works.","",bc_self;
	end;
}

sp_cor,169,282,3	script	Worker#cor_other_06	4_M_DWARF,{
	npctalk "How long should I chop wood? Can't I just chop them off?","",bc_self;
	end;
}

sp_cor,184,279,5	script	Worker#cor_other_07	4_M_05,{
	npctalk "Huh.. I can breathe now. How old do I look? Don't call me grandpa just because you're younger than you imagine how old I am.","",bc_self;
	end;
}

sp_cor,209,280,1	script	Worker#cor_other_08	4_F_TWMIDWOMAN,{
	npctalk "What's this mansion? That's what I don't know. It's been here since we arrived.","",bc_self;
	end;
}

sp_cor,45,135,5	script	Worker#cor_other_09	2_M_OLDBLSMITH,{
	npctalk "I kept chopping down the trees... What are they going to do with all of this now?","",bc_self;
	end;
}

sp_cor,136,180,3	script	Worker#cor_other_10	1_M_JOBGUIDER,{
	setpcblock PCBLOCK_ALL,true;
	emotion ET_CRY;
	npctalk "I think... Our Coco... Where has he been...","",bc_self;
	sleep2 1500;
	npctalk "Don't cry. He'll be back soon. He's smart, Annie.","Worker#cor_other_11",bc_self;
	setpcblock PCBLOCK_ALL,false;
	end;
}

sp_cor,138,180,3	script	Worker#cor_other_11	1_F_02,{
	npctalk "My dog ran away from the camp and he hasn't came back. I have to go look for him.","",bc_self;
	end;
}

sp_cor,151,180,5	script	Worker#cor_other_12	4_M_RUSMAN2,{
	switch(finding_patrick){
		case 3:
			mes "[ Worker ]";
			mes "Huh... I don't want to wash these things, uh... it seems like the inside is burnt.";
			next;
			mes "[ Worker ]";
			mes "Hey, don't come any closer. These are contaminated items. Look out.";
			next;
			select("I have something to ask you.");
			mes "[ Worker ]";
			mes "Oh, you saved us! My name is Marcus. What are you doing here?";
			npctalk "Nice to meet you, my name is Marcus.","",bc_self;
			next;
			select("Marcus Holzman from Lighthalzen?");
			mes "[ Marcus ]";
			mes "Do you know me? I don't know you....";
			next;
			select("Are you familiar with Eva?");
			mes "[ Marcus ]";
			mes "No, who are you, really? How do you know Eva Mueller? Did Eva send you? How is she doing? Oh my god! Eva! How is Eva doing?";
			npctalk "Aaah... Eva, my dear Eva....","",bc_self;
			next;
			mes "[ Marcus ]";
			mes "Eva, I want to see Eva again. Did she forget about me? I haven't been able to contact her for several years.";
			npctalk "Ah, ahah.. I'm really a terrible person...","",bc_self;
			next;
			select("She worries because she hasn't been contacted.");
			mes "[ Marcus ]";
			mes "I couldn't send letters. I couldn't contact the outside either, and I can't get out of here. These are the rules of this place.";
			next;
			select("Well, it says you're on vacation.");
			mes "[ Marcus ]";
			mes "Vacation? I've been working everyday since I've came here. What makes you say that?";
			npctalk "That's new to me.","",bc_self;
			next;
			select("I'm investigating missing people.");
			mes "[ Marcus ]";
			mes "I can't thank you enough.";
			next;
			select("I can forward your letters for you.");
			mes "[ Marcus ]";
			mes "Really... you'd do that for me.... if we had meet sooner, we'd have been long life friends. If you need help with anything, let me know.";
			next;
			select("Do you know Patrick Kaufman?");
			mes "[ Marcus ]";
			mes "It's a familiar name... Patrick... Patrick... Are you talking about Pat who was cleaning the labs?";
			mes "Wasn't he the guy who came from Lighthalzen too?";
			next;
			select("Yes, that's him.");
			mes "[ Marcus ]";
			mes "That's right, that's right! The guy who looked tall and big. I wanted to be his friend becase we came from the same place. I couldn't see him one day. Then I was moved.";
			next;
			mes "[ Marcus ]";
			mes "It was a Facility Maintenance Department, I told them things weren't supposed to work that way.";
			next;
			mes "[ Marcus ]";
			mes "I'm ^0000FFfamiliar with the people^000000 who work in the lab, I've seen him a few times as I passed by. Did he stop working there?";
			next;
			mes "[ Marcus ]";
			mes "Anyway, if you want to know more, check out the <NAVI>[incinerator]<INFO>sp_cor,70,263,0,101,0</INFO></NAVI>.";
			mes "They're working on collecting and sorting the scattered materials, so maybe they know something else about Pat.";
			next;
			mes "[ Marcus ]";
			mes "These laundries will be moved to the incinerator soon. Huh, not good. If you pass them once in the washing machine, they won't always be clean...";
			next;
			mes "[ Marcus ]";
			mes "Thank you. I have written many letters during my stay, so I'll sort them out. Thank you again!";
			finding_patrick = 4;
			completequest 17022;
			setquest 17023;
			questinfo_refresh();
			end;
			
		case 4:
			mes "[ Marcus ]";
			mes "Anyway, if you want to know more, check out the <NAVI>[incinerator]<INFO>sp_cor,70,263,0,101,0</INFO></NAVI>.";
			mes "They're working on collecting and sorting the scattered materials, so maybe they know something else about Pat.";
			end;
	}
	mes "[ Marcus ]";
	mes "Huh... I don't want to wash these things, uh... it seems like the inside is burnt.";
	close;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"finding_patrick == 3";
end;
}

sp_cor,172,187,1	script	Worker#cor_other_13	4_F_HUGRANMA,{
	npctalk "I'm glad you didn't have anything to do with me.","",bc_self;
	end;
}

sp_cor,173,189,3	script	Worker#cor_other_14	4_M_RUSBALD,{
	npctalk "I can't find the bathroom! I can't hold it in anymore... perhaps the trees over there could do...","",bc_self;
	end;
}

sp_cor,234,113,3	script	Worker#cor_other_15	4_COOK,{
	npctalk "Wait? How many more do we need?","",bc_self;
	end;
}

sp_cor,132,144,3	script	Worker#os_red	4_F_05,{
	switch(finding_patrick){
		case 1:
			mes "[ Worker ]";
			mes "I'll have to split the workforce because I only have so few people remaining.";
			npctalk "I have to split the workforce.","",bc_self;
			next;
			mes "[ Worker ]";
			mes "We'll have to take turns.";
			npctalk "No, that's not very productive.","Worker#os_lady",bc_self;
			next;
			select("Do you know Patrick Kaufman?");
			mes "[ Worker ]";
			mes "Who?";
			npctalk "Pat, who?","Worker#os_sit",bc_self;
			next;
			select("Patrick Kaufman. Facility Maintenance Officer.");
			mes "[ Worker ]";
			mes "Patrick Kaufman? Don't you mean Patrick Young?";
			npctalk "I don't think that's the right name.","Worker#os_stand",bc_self;
			next;
			mes "[ Worker ]";
			mes "He's the logistic guy.";
			npctalk "Facility Maintenance Department....","Worker#os_lady",bc_self;
			next;
			mes "[ Worker ]";
			mes "Where's the facility department here?";
			npctalk "Don't you know?","",bc_self;
			next;
			mes "[ Worker ]";
			mes "I knew before I came here!";
			npctalk "That's not possible.","Worker#os_stand",bc_self;
			next;
			mes "[ Worker ]";
			mes "Patrick is in the Facility Maintenance Department? That I didn't know. Nobody here worked as their usual job. When I got here, I was assigned a different job.";
			next;
			select("Who decides what you guys do?");
			mes "[ Worker ]";
			mes "Who decides? It's the researchers.";
			mes "When we arrived here, we were set up in a line and then one after the other, we were interviewed. Then we were assigned a job.";
			npctalk "Was I given the job of taking care of the livestock so that we could survive?","",bc_self;
			next;
			mes "[ Worker ]";
			mes "When I think about it, his eyes were so beautiful.";
			npctalk "That's right.","Worker#os_lady",bc_self;
			next;
			mes "[ Worker ]";
			mes "Anyway, if you're looking for someone in particular, you should ^0000FFask the researchers.^000000 Most of them already ran away, but a few stayed behind.";
			mes "The <NAVI>[researcher]<INFO>sp_cor,224,77,0,101,0</INFO></NAVI> right next to the crops. Do you see her?";
			completequest 17020;
			setquest 17021;
			finding_patrick = 2;
			questinfo_refresh();
			end;
			
		case 2:
			mes "[ Worker ]";
			mes "Anyway, if you're looking for someone in particular, you should ^0000FFask the researchers.^000000 Most of them already ran away, but a few stayed behind.";
			mes "The <NAVI>[researcher]<INFO>sp_cor,224,77,0,101,0</INFO></NAVI> right next to the crops. Do you see her?";
			end;
	}
	mes "[ Worker ]";
	mes "Now I can't think of anything else, I'm in a bad mood. I'll get back to work soon...";
	close;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"finding_patrick == 1";
end;
}

sp_cor,133,142,3	script	Worker#os_sit	4_M_SITDOWN,{
	mes "[ Worker ]";
	mes "I can't stand now, I was soaked in blood earlier. I would have followed them but I couldn't stand.";
	close;
}

sp_cor,130,143,5	script	Worker#os_lady	1_M_INNKEEPER,{
	mes "[ Worker ]";
	mes "Hey, what the hell is this commotion all about?";
	close;
}

sp_cor,129,140,3	script	Worker#os_stand	1_M_ORIENT01,{
	mes "[ Worker ]";
	mes "For whom and for what have I been working for... they have so much resources...";
	close;
}

sp_cor,117,268,1	script	Scout#cor_00	4_F_GUNSLINGER2,{
	npctalk "What are you doing here?","",bc_self;
	sleep2 1500;
	npctalk "Don't get too close.","Scout#cor_01",bc_self;
	end;
}

sp_cor,119,266,1	script	Scout#cor_01	4_M_REBELLION2,{
	npctalk "There is no danger here, but you shouldn't get too close.","",bc_self;
	end;
}

sp_cor,153,260,3	script	Scout#cor_02	4_F_REBELLION3,{
	npctalk "I tracked a load that carries freight. It was nice effort. But where is the train?","",bc_self;
	end;
}

sp_cor,166,139,3	script	Scout#cor_03	4_M_GUNSLINGER3,{
	npctalk "It's a pod lot? I'd love to eat been noodles~ But we can't eat them yet. I wish we could...","",bc_self;
	end;
}

sp_cor,170,189,5	script	Scout#cor_04	4_M_REBELLION3,{
	setpcblock PCBLOCK_ALL,true;
	npctalk "Really? Then I don't know anything.","",bc_self;
	sleep2 1500;
	npctalk "Well, they'll only really work in their labs, so they barely had time to eat.","Worker#cor_other_13",bc_self;
	sleep2 1500;
	npctalk "They must have been really scared.","",bc_self;
	sleep2 1500;
	npctalk "I didn't know that! Hah...","Worker#cor_other_14",bc_self;
	setpcblock PCBLOCK_ALL,false;
	end;
}

sp_cor,137,149,7	script	Sentinel#cor_00	4_F_REBELLION3,{
	mes "[ Sentinel ]";
	mes "You can rest assured, there are eyes everywhere here. I'm being careful.";
	close;
}

sp_cor,136,128,5	script	Sentinel#cor_01	4_M_REBELLION,{
	mes "[ Sentinel ]";
	mes "It's safe here. Even if it's a big place, they won't attack randomly.";
	close;
}

sp_cor,117,132,3	script	Sentinel#cor_02	4_M_GUNSLINGER2,{
	mes "[ Sentinel ]";
	mes "If we're going to have a raid next time, we'll have to be thorough.";
	close;
}

sp_cor,118,148,7	script	Sentinel#cor_03	4_F_REBELLION2,{
	mes "[ Sentinel ]";
	mes "There's nothing that stands out in this location!";
	close;
}

sp_cor,232,289,5	script	Rebellion#cor_00	4_F_REBELLION2,{
	mes "[ Rebellion ]";
	mes "Scientists, researchers, everyone here just pretends things are fine.";
	mes "Arthur, don't touch these or your hands will melt.";
	close;
}

sp_cor,235,292,7	script	Rebellion#cor_01	4_M_REBELLION2,{
	mes "[ Rebellion ]";
	mes "Are these expensive? I want to see them closer! I want to smell it!";
	mes "The feeling of something valuable!";
	close;
}

sp_cor,260,280,3	script	Rebellion#cor_03	4_F_ANYA,{
	npctalk "We're on high alert! Keep a lookout!","",bc_self;
	end;
}

sp_cor,130,222,1	script	Rebellion#cor_barracks_1	4_F_REBELLION2,{
	npctalk "We can't predict what these items will do yet, there might be a risk. Don't come any closer, adventurer.","",bc_self;
	end;
}

sp_cor,152,224,1	script	Rebellion#cor_barracks_2	4_F_ANYA,{
	npctalk "I'm writing a book, but there's so many things I don't know. I want to do it all by myself.","",bc_self;
	end;
}

sp_cor,154,223,1	script	Rebellion#cor_barracks_3	4_M_REBELLION3,{
	npctalk "I'm standing here, even though I don't know anything.","",bc_self;
	end;
}

sp_cor,224,77,3	script	Researcher#cor_00	4_F_SCIENCE,{
	switch(finding_patrick){
		case 2:
			mes "[ Researcher ]";
			mes "Anyway, what about all of these...?";
			mes "It's too bad that they won't be used.";
			next;
			mes "[ Researcher ]";
			mes "You... you're the adventurer that came with the gunmen. Am I in trouble? I didn't know anything about these illegal experiments or the institute.";
			next;
			select("I'm looking for a person.");
			mes "[ Researcher ]";
			mes "Who? Patrick? I don't know him. I don't know many peopl, I'm only focused on the field work here.";
			npctalk "I can tell you the names of all the vegetables.","",bc_self;
			next;
			select("Why are the researchers doing the field work?");
			mes "[ Researcher ]";
			mes "Well... in short, it was to feed the study animals, I was growing super vegetables that would sustain the animals for life.";
			next;
			mes "[ Researcher ]";
			mes "Processing and refining the vegetables... with these... what were they trying to do?? Did they try solve the hunger problems?";
			mes "Actually, I don't know. Maybe you do.";
			next;
			mes "[ Researcher ]";
			mes "The chief researchers here know all the details. I honestly didn't know they would just leave like that. I thought they were like a family to me...";
			next;
			mes "[ Researcher ]";
			mes "The chief told me to pack my bags because there was a disturbance outside. I was hesitating because I had to take care of my crops, but then everyonen had already left.";
			npctalk "I feel discarded.","",bc_self;
			next;
			mes "[ Researcher ]";
			mes "I understood the moment I heard the Vice President talking. I worked with pride, but I was only making consumables for my senior researcher in the end.";
			next;
			mes "[ Researcher ]";
			mes "After all, I was blinded by my own ego. I didn't realize anything of what was happening.";
			npctalk "I finally understood the true meaning...","",bc_self;
			next;
			mes "[ Researcher ]";
			mes "Anyway, I'm looking for a <NAVI>[person]<INFO>sp_cor,151,180,0,000,0</INFO></NAVI> to do my laundry. It's been a while and my feet are dirty.";
			finding_patrick = 3;
			completequest 17021;
			setquest 17022;
			getexp 300000,300000;
			questinfo_refresh();
			end;
			
		case 3:
			mes "[ Researcher ]";
			mes "Anyway, I'm looking for a <NAVI>[person]<INFO>sp_cor,151,180,0,000,0</INFO></NAVI> to do my laundry. It's been a while and my feet are dirty.";
			end;
	}
	mes "[ Researcher ]";
	mes "Anyway, how about all of these...?";
	mes "I'm afraid they will go to waste if I just leave.";
	close;
	
OnInit:
	questinfo QTYPE_QUEST,QMARK_YELLOW,"finding_patrick == 2";
end;
}

//= < Mob Spawn >
sp_os,0,0	monster	Bellare	20355,110,5000
sp_os,0,0	monster	Sanare	20357,110,5000
sp_os,0,0	monster	Venenum	20357,5,5000
sp_rudus,0,0	monster	Venenum	20363,38,5000
sp_rudus,0,0	monster	Dolor	20361,59,5000
sp_rudus,0,0	monster	Twin Caput	20365,43,5000
sp_rudus2,0,0	monster	Greater Bellare	20356,40,5000
sp_rudus2,0,0	monster	Greater Sanare	20358,37,5000
sp_rudus2,0,0	monster	Mutant Plaga	20360,53,5000
sp_rudus2,0,0	monster	Mutant Dolor	20362,45,5000
sp_rudus2,0,0	monster	R48-85-BESTIA	20381,1,21600000,600000,0
sp_rudus3,0,0	monster	Mutant Dolor	20362,60,5000
sp_rudus3,0,0	monster	Mutant Plaga	20360,53,5000
sp_rudus3,0,0	monster	Mutant Venenum	20364,64,5000
sp_rudus3,0,0	monster	Mutant Twin Caput	20366,65,5000

//= < Warp NPC >
pub_cat,104,106,3	script	Retired Rebellion#backroom_ent	4_M_SEAMAN,{
	if(ep_illusion < 8){
		npctalk "Retired Rebellion: Go to another place. This place is not for you.","",bc_self;
		end;
	}
	mes "[ Retired Rebellion ]";
	mes "Are you going to the backroom?";
	next;
	if(select("Yes.:Not yet.") == 2){
		mes "[ Retired Rebellion ]";
		mes "Take your time.";
		end;
	}
	warp "pub_cat",150,105;
	end;
}

ein_fild05,156,288,1	script	Rebellion Crew#rudus_ent	4_M_REBELLION2,{
	if(ep_illusion < 3){
		mes "[ Rebellion Crew ]";
		mes "I'm sorry, but you're not allowed to go inside.";
		mes "It's dangerous at the moment because the mine is closed.";
		end;
	}
	mes "[ Rebellion Crew ]";
	mes "Hello adventurer!";
	mes "This way, I'll let you in the mines.";
	close2;
	warp "sp_rudus",200,377;
	end;
}

sp_rudus,197,282,0	script	Firmly Closed Gate#171_in	4_ENERGY_BLUE,{
	if(ep_illusion < 6){
		mes "[ Rookie ]";
		mes "Aaaah... I haven't finished yet.";
		mes "It's more secure than I thought.";
		close;
	}
	getmapxy(.@map$,.@x,.@y,BL_PC);
	if(.@y <= 281) end;
	if(select("Jump over the barrier.:Go back.") == 1)
		warp "sp_rudus",197,267;
	end;
}

sp_rudus,197,272,0	script	Firmly Closed Gate#171_out	4_ENERGY_BLUE,{
	getmapxy(.@map$,.@x,.@y,BL_PC);
	if(.@y >= 272) end;
	if(select("Jump the barrier.:Go back.") == 1)
		warp "sp_rudus",197,288;
	end;
}

ein_fild03,288,270,0	script	ein05_to_spcor	WARPNPC,2,2,{
	if(ep_illusion < 34){
		mes "- You're not allowed to enter this area. -";
		end;
	}
	warp "sp_os",188,63;
	end;
}

lighthalzen,53,279,0	script	lhz_to_rekenber	WARPNPC,1,1,{
	end;

OnTouch:
	if(ep_illusion < 13){
		npctalk "Rekenber Guard : This place is restricted from outsider.","Rekenber Guard Oscar#171_light",bc_self;
		end;
	}
	warp "rgsr_in",127,38;
	end;
}

sp_os,260,363,0	script	sp_os_to_sp_cor	WARPNPC,1,1,{
	end;
	
OnTouch:
	if(ep_illusion < 35){
		mes "- You can't enter yet. -";
		close;
	}
	warp "sp_cor",163,60;
	end;
}

pub_cat,44,27,0	warp	pub_to_ein	1,1,einbroch,302,326
einbroch,302,331,0	warp	ein_to_pub	1,1,pub_cat,49,27
sp_rudus,200,382,0	warp	rudus_to_field	1,1,ein_fild05,158,289
pub_cat,146,105,0	warp	backroom_exit	1,1,pub_cat,100,106
sp_rudus,180,258,0	warp	rudus1_to_rudus2	1,1,sp_rudus2,185,258
sp_rudus2,180,258,0	warp	rudus2_to_rudus1	1,1,sp_rudus,185,258
sp_rudus2,359,206,0	warp	rudus2_to_rudus3	1,1,sp_rudus3,366,207
sp_rudus3,371,207,0	warp	rudus3_to_rudus2	1,1,sp_rudus2,355,206
sp_cor,162,41,0	warp	sp_cor_to_sp_os	1,1,sp_os,260,357
sp_os,188,30,0	warp	sp_os_exit	1,1,ein_fild03,284,267
rgsr_in,127,32,0	warp	rekenber_to_lhz	1,1,lighthalzen,53,275


//= < Mapflags >
1@rgsr	mapflag	nowarp
1@rgsr	mapflag	nomemo
1@rgsr	mapflag	noteleport
1@rgsr	mapflag	monster_noteleport
1@rgsr	mapflag	nosave
1@rgsr	mapflag	nobranch
1@rgsr	mapflag	nowarpto
1@rgsr	mapflag	noicewall
1@rgsr	mapflag	restricted	9
1@os_a	mapflag	nowarp
1@os_a	mapflag	nomemo
1@os_a	mapflag	noteleport
1@os_a	mapflag	monster_noteleport
1@os_a	mapflag	nosave
1@os_a	mapflag	nobranch
1@os_a	mapflag	nowarpto
1@os_a	mapflag	noicewall
1@os_a	mapflag	restricted	9
1@os_b	mapflag	nowarp
1@os_b	mapflag	nomemo
1@os_b	mapflag	noteleport
1@os_b	mapflag	monster_noteleport
1@os_b	mapflag	nosave
1@os_b	mapflag	nobranch
1@os_b	mapflag	nowarpto
1@os_b	mapflag	noicewall
1@os_b	mapflag	restricted	9
1@cor	mapflag	nowarp
1@cor	mapflag	nomemo
1@cor	mapflag	noteleport
1@cor	mapflag	monster_noteleport
1@cor	mapflag	nosave
1@cor	mapflag	nobranch
1@cor	mapflag	nowarpto
1@cor	mapflag	noicewall
1@cor	mapflag	restricted	9