// pub_hongfunv.h ���Ů(����̫�ͳ�)
// jaja 2002-11-24

NPC_BEGIN(CNpub_hongfunv);

virtual void create()
{
	set_name("���Ů", "hongfu nv");
	set("title", "�糾����֮");
	set("gender", "Ů��");
	set("age", 20);
	set("level", 200);

	set("icon", 11);				//������������
	set("per", 40);
	set("repute", 10000);
	set("couple/id", "li jin");
	set("couply/gender", "�Ϲ�");
	set("couple/name", "�");

	create_family("����", 2, "����");
	
	set("str", 46);
	set("int", 40);
	set("con", 26);
	set("dex", 50);
	
	set("chat_chance_combat", 20);
		
	set("max_hp", 30000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 80);
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350+random(50));		
	set_skill("yunv_xinjing", 350+random(50));	
	set_skill("unarmed", 350+random(50));	
	set_skill("meinv_quan", 350+random(50));
	set_skill("dodge", 350+random(50));
	set_skill("yueying_wubu", 350+random(50));	
	set_skill("parry", 350+random(50));
	set_skill("blade", 350+random(50));
	set_skill("missblade", 350+random(50));

	map_skill("force", "yunv_xinjing");	
	map_skill("blade", "missblade");
	map_skill("dodge", "yueying_wubu");
	map_skill("parry", "missblade");
	map_skill("unarmed", "meinv_quan");	

	set("apply/armor", 330);
	set("apply/damage", 200);

	carry_object("gangdao")->wield();	
	carry_object("baipao")->wear();
	carry_object("xiao");
	add_money(5000);
	set("jv",100);
	if(random(2)==0)
		set("jp","baomingdan");
	else
		set("jp","hanyuepai");

	if(!random(3))
	{
		set_temp("apply/no_ǧ���׹�",1);
		set_temp("apply/no_��˼����",1);
		set_temp("apply/no_�ƺ�����",1);
		set_temp("apply/no_���־�",1);
		set_temp("apply/no_�������",1);
		set_temp("apply/no_ƴ��",1);
		set_temp("apply/no_��Ѫ��",1);
		
		set("bigboss",1);
	}
}

virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(4))
	{
	case 0:
		perform_action("force powerup", 0);	
		break;
	case 1:
		perform_action("blade xiangsi", 1);	
		break;
	case 2:
		perform_action("force recover", 0);	
		break;
	case 3:
		if(! query_weapon())
			carry_object("gangdao")->wield();	
		else
			perform_action("blade xiangsi", 1);	
		break;
	}	
	return 0;
}

virtual void die()
{
	if(random(query("jv"))==0)
		load_item(querystr("jp"))->move(this);
	CNpc::die();
}

NPC_END;
