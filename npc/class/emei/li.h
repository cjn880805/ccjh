//li.h
//Lanwood 2000-01-06

NPC_BEGIN(CNemei_li);

virtual void create()
{
	set_name("������", "li minghua");
	set("long",  "���Ƕ����ɵĵ��Ĵ��׼ҵ��ӡ�");
	set("gender", "Ů��");
	set("age", 23);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "fighter");
	set("icon", young_woman3);
		set("foolid",22);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3000);
	
	set("mp", 1500);
	set("max_mp", 1500);
	
	set("combat_exp", 150000);
	set("score", 1000);
	set_skill("persuading", 50);
	set_skill("throwing", 30);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("finger", 85);
	set_skill("parry", 70);
	set_skill("strike", 60);
	set_skill("sword", 60);
	set_skill("jinding_zhang", 60);
	set_skill("tiangang_zhi", 85);
	set_skill("huifeng_jian", 60);
	set_skill("zhutian_bu", 80);
	set_skill("linji_zhuang", 80);
	map_skill("force","linji_zhuang");
	map_skill("finger","tiangang_zhi");
	map_skill("dodge","zhutian_bu");
	map_skill("strike","jinding_zhang");
	map_skill("sword","huifeng_jian");
	map_skill("parry","huifeng_jian");
	
	create_family("������", 4, "����");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
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

NPC_END;