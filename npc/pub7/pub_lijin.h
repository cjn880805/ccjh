// pub_lijin.h �
// dieer 2002-8-5

NPC_BEGIN(CNpub_lijin);

virtual void create()
{
	set_name("�", "li jin");
	set("title", "�糾����֮");
	set("gender", "����");
	set("age", 20);
	set("level", 200);

	set("icon", 30);
	set("per", 40);
	set("repute", 10000);

	set("couple/id", "hongfu nv");
	set("couply/gender", "����");
	set("couple/name", "���Ů");

	create_family("����", 2, "����");
	
	set("str", 48);
	set("int", 38);
	set("con", 33);
	set("dex", 50);
	
	set("chat_chance_combat", 20);
		
	set("max_hp", 30000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 80);	
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350+random(50));
	set_skill("xiantian_qigong", 350+random(50));	
	set_skill("cuff", 350+random(50));
	set_skill("jinyu_quan", 350+random(50));
	set_skill("dodge", 350+random(50));
	set_skill("xianyun_bufa", 350+random(50));	
	set_skill("parry", 350+random(50));
	set_skill("sword", 350+random(50));
	set_skill("misssword", 350+random(50));
	set_skill("tianluo_diwang", 350+random(50));

	map_skill("force", "xiantian_qigong");	
	map_skill("sword", "misssword");
	map_skill("dodge", "xianyun_bufa");	
	map_skill("parry", "misssword");
	map_skill("cuff", "jinyu_quan");

	prepare_skill("cuff", "jinyu_quan");

	set("apply/armor", 330);
	set("apply/damage", 200);

	carry_object("changjian")->wield();	
	carry_object("baipao")->wear();
	carry_object("qin");
	add_money(5000);
}
virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(3))
	{
	case 0:
		perform_action("force powerup", 0);	
		break;
	case 1:
		perform_action("sword xiangsi", 1);	
		break;
	case 2:
		perform_action("force recover", 0);	
		break;
	}	
	return 0;
}
/*
virtual char * chat_msg()
{
	CFightRoom * obj;
	CContainer * env = environment();
	//��鷿�����Ƿ���ս��
	if( (obj = (CFightRoom *)env->present("fight_room")) )
	{
		CContainer * obj1 = environment();
		DTItemList * list = obj1->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj2 = list->GetNext(p);
			if(! obj2->is_character()) continue; 
			CChar * npc = (CChar *)obj2;  
			if(userp(npc))	continue;
			if(EQUALSTR(npc->querystr("couple/name"),"�"))
			{
				int team;
				CFightRoom * obj3=(CFightRoom *)npc->environment();
				if(npc->query_temp("fight/fight_team"))		//����A��
					team = 1;
				else
					team = 0;
				move(obj3);
				obj3->Join_Team(this, team);
			}
			break;
		}
	}
	return 0;
}
*/
NPC_END;