NPC_BEGIN(CNPub_dipi);

virtual void create()
{
	set_name("��Ʀ","dipi");

	set("icon", cateran);
	set("gender", "����" );
	set("age", 20);
	set("long", "����һ���ȵ��������ĵ�Ʀ��");
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set("combat_exp", 750);
	set("shen_type", -1);
	set("str", 25);
	set("dex", 20);
	set("con", 18);
	set("int", 15);
	set("attitude","heroism");
	set("chat_chance", 5);
	
//	carry_object("cloth")->wear();
	
	
};

virtual char * chat_msg(CChar * me)
{
	switch(random(2))
	{
	case 0:
		return "��Ʀ���Ժ����ĺ������������ð�������ְ�������";
	case 1:
		return "��Ʀ����ǽ�ǣ������������������";
	}
	return "";
}

NPC_END;
