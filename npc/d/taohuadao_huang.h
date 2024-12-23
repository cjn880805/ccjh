// taohuadao_huang.c
//code by Fisho
//date:2000-12-22
//inherit F_MASTER;

NPC_BEGIN(CNtaohuadao_huang);

virtual void create()
{
    set_name("�ض�",  "huang rong" );
    set("gender", "Ů��");
    set("age", 36);
        set("icon",young_woman10);

    set("long", "���Ǳ��������ķ��ˣ����Ϲֵİ�Ů��ǰ��ؤ�������");
	
    set("attitude", "peaceful");
	
    set("per", 30);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);
	
    set("hp", 2000);
    set("max_hp", 2000);
    set("mp", 2000);
    set("max_mp", 2000);
    set("mp_factor", 0l);
	
    set("combat_exp", 500000);
    
	
    set_skill("force", 120);
    set_skill("bibo_shengong", 120);
    set_skill("unarmed", 120);
    set_skill("luoying_shenzhang", 120);
    set_skill("dodge", 180);
    set_skill("anying_fuxiang", 120);
    set_skill("parry", 120);
    set_skill("sword", 120);
    set_skill("luoying_shenjian", 120);
    set_skill("qimen_wuxing", 120);
	
    map_skill("force"  , "bibo_shengong");
    map_skill("unarmed", "luoying_shenzhang");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("sword"  , "luoying_shenjian") ;
	
	set_inquiry("����","�������Ϻ��ҵ�������ȥ���ҵ���취Ū�����ǵĶ������С�����");

    create_family("�һ���", 2, "����");
	
    carry_object("ruanwei")->wear();
    carry_object("shudai")->wear();
	set("no_huan",1);
	
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "damo ling") || DIFFERSTR(ob->querystr("name"), "��Ħ��" ))
	{	
		message_vision("$N����ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "������", "qingyue pai");

	message_vision("$N���ͷ��͵͵��$nһ�鶫����", this, who);
	ob->move(who);

	return 1;
}


NPC_END;