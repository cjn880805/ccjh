//sihu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_sihu);

virtual void create()
{
	set_name("�����Ļ�","sihu");

	set("icon", young_man2);
	set("gender", "����");
	set("nickname", "����");
	set("age", 19);
	set("long", "����һ�����޾��ˣ��ֽŴִ��������ˣ�ȴ���Դ��ӡ�");
	
	set("combat_exp", 100000);
	

	set("attitude", "peaceful");
	
	set_skill("unarmed", 90);
	set_skill("dodge", 90);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);

	carry_object("cloth")->wear();
	add_money(2);


};

NPC_END;
