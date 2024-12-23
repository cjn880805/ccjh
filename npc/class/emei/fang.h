//fang.h
//Lanwood 2000-01-06

NPC_BEGIN(CNemei_fang);

virtual void create()
{
	set_name("������", "fang biyin");
	set("long",  "���Ƕ����ɵĵ��Ĵ��׼ҵ��ӡ�");
	set("gender", "Ů��");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("repute", 10000);
	set("class", "fighter");
	set("icon", young_woman9);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
		set("foolid",2);
	set("max_hp", 1000);
	
	set("mp", 1500);
	set("max_mp", 1500);
    
	set("combat_exp", 150000);
	set("score", 1000);
	set_skill("persuading", 40);
	set_skill("throwing", 30);
	set_skill("force", 60);
	set_skill("dodge", 80);
	set_skill("finger", 50);
	set_skill("parry", 70);
	set_skill("strike", 80);
	set_skill("blade", 60);
	set_skill("jinding_zhang", 80);
	set_skill("tiangang_zhi", 50);
	set_skill("yanxing_dao", 60);
	set_skill("zhutian_bu", 80);
	set_skill("linji_zhuang", 60);
	
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("blade","yanxing_dao");
	map_skill("parry","yanxing_dao");
	
	create_family("������", 4, "����");
	set_inquiry("����","��������Ҳͦ���ģ���һ���õ�����Ѷ�û�С�");
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
	set("no_huan",1);
};

virtual void attempt_apprentice(CChar * me)
{
	char msg[255];

   if (me->query_combat_exp() > 10000) 
   {
        say("�Ҷ���ע�����ޣ��Ե���Ҫ�������ܼ�į��", me);
        say(snprintf(msg, 255, "�ڽ����������棬%s�����ḻ���Ƿ����ڶ����޵���", query_respect(me)), me);
		SendMenu(me);
        return;
   }

   if (me->query("repute") < 0)
   {
		say("�Ҷ������������������ɣ��Ե���Ҫ���ϡ�", me);
		say(snprintf(msg, 255, "�ڵ��з��棬%s�Ƿ����ò�����", query_respect(me)), me);
		SendMenu(me);
		return;
   }

   say("�ðɣ��Ҿ��������ˡ�");
   command(snprintf(msg, 255, "recruit %ld", me->object_id()));
}


virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "pink cloth") || DIFFERSTR(ob->querystr("name"), "�ۺ����") )
	{	
		message_vision("$N����ĵ�������ʲô������", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "������", "anyue pai");

	message_vision("$N���ͷ��͵͵��$nһ�鶫����", this, who);
	ob->move(who);

	return 1;
}



NPC_END;
