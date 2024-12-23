//xianghuo.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xianghuo);

virtual void create()
{
	
	set_name("������","xianghuo");
	
	set("icon", taoist);
	set("age", 32);
	set("gender", "����");
	set("long","�䵱���ķ����ĵ��ӡ�");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", 1);
	
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 30);
	set("chat_chance", 5);
	create_family("�䵱��", 4, "����");
	
	carry_object("changjian");
	carry_object("white_robe")->wear();
	
};

virtual char * chat_msg(CChar * me)
{
	return "�����˰��־ٵ�����ǰ���������Ǯ�ɣ������ٷ�";
}
NPC_END;
