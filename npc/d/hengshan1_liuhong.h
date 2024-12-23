//liuhong.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHengShan1_liuhong);

virtual void create()
{

		set_name("����","liu hong");

	set("foolid",143);        set("gender", "Ů��");
        set("class", "swordsman");
        set("long", "����������Ů����");
        set("age", 17);
        set("attitude", "peaceful");
        set("per", 29);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
 	set("icon",young_woman11);

        set("mp", 500);
        set("max_mp", 500);
        set("mp_factor", 10);
        set("max_hp",700);
        set("combat_exp", 100000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("force", 40);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("hengshan_sword", 40);
        set_skill("lingxu_bu", 40);

        map_skill("sword", "hengshan_sword");
        map_skill("parry", "hengshan_sword");
        map_skill("dodge", "lingxu_bu");

        create_family("��ɽ��", 14, "����");

		set_inquiry("����","�����ڵ������ǻ��÷ׯ�������ҡ���");

        carry_object("changjian")->wield();
        carry_object("female1_cloth")->wear();
		set("no_huan",1);
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "ling pai") || DIFFERSTR(ob->querystr("name"), "÷������") )
	{	
		message_vision("$N����ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "б����", "xieyue pai");

	message_vision("$N���ͷ��͵͵��$nһ�鶫����", this, who);
	ob->move(who);

	return 1;
}



NPC_END;