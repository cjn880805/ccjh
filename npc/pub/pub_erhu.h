NPC_BEGIN(CNPub_erhu);

virtual void create()
{
	set_name("���׶���","erhu");

	set("icon", triggerman2);
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
	add_money(200);
};

NPC_END;
