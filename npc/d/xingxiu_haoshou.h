// xingxiu_haoshou.c ����

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxingxiu_haoshou);

virtual void create()
{
	set_name("�����ɺ���", "haoshou" );
	set("long", "���������ɵĴ����֡� ����������һֻͭ�ţ�������������ش��š� ");
	set("gender", "����");
	set("age", 33);
        set("icon",young_man2);

	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	
	set("max_hp", 900);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 10);
	set("combat_exp", 3000);
	
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	
//	carry_object("tonghao")->wield();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "�����ɺ���˵�������ǡ��ޡ��ϡ��ɣ�������御���� ";
	case 1:
		return "�����ɺ���˵�������ǡ��ޡ��ϡ��ɣ��¡��䡫�졫�ء��� ";
	case 2:
		return "�����ɺ���˵�������ǡ��ޡ��ϡ��ɣ��š����ޡ��ȡ��� ";
	}
	return "";
}

NPC_END;