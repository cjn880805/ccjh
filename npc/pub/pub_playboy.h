NPC_BEGIN(CNPub_playboy);

virtual void create()
{
	set_name("��������","playboy");

	set("icon", young_man6);
	set("nickname", "�ɻ����");
	set("gender", "����" );
	set("age", 19);
	set("long", "���Ǹ����������Ļ������ӡ�");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	
	set("max_hp", 1200);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);
	carry_object("male8_cloth")->wear();
	carry_object("menghan_yao")->wear();
	add_money(10);

};

virtual  char * greeting(CChar * me )
{
	static char msg[255];

	if(EQUALSTR(me->querystr("gender"), "Ů��"))
		return snprintf(msg, 255, " ��������ɫ����˵��%s������ô�ż���·���������治����", query_respect(me));

	return snprintf(msg, 255, " �������ӳ�����·�ߵ�Ұ�����ɰײ���~~����λ%s��˵����", query_respect(me));
   

}

NPC_END;




