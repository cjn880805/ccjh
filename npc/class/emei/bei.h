//bei.h
//Lanwood 2000-01-06

NPC_BEGIN(CNemei_bei);

virtual void create()
{
	set_name("������", "bei siuyi");
	set("long",  "���Ƕ����ɵĵ��Ĵ��׼ҵ��ӡ�");
	set("gender", "Ů��");
	set("age", 21);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("icon", young_woman8);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3000);
		set("foolid",24);
	set("mp", 1500);
	set("max_mp", 1500);
	
	set_inquiry("���콣", "ʦ������������ʦ��ˡ�");
	set_inquiry("��Сܽ", ask_for_ji);
	
	set("combat_exp", 150000);
	set("score", 1000);
	set_skill("throwing", 30);
	set_skill("persuading", 50);
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

static char * ask_for_ji(CNpc * me, CChar * who)
{
    me->set("marks/ji", 1);
    return "��Сܽ���������ء��������벻�����ˣ�"; 
}

NPC_END;
