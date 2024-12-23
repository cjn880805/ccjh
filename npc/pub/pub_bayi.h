NPC_BEGIN(CNPub_bayi);

virtual void create()
{
	set_name("����","bayi");

	set("icon", pub_boss);
	set("gender", "����");
	set("age", 55);
	
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);
	set("attitude","heroism");
	
	set_inquiry("����" , "�����Ű�����İ취���˺ö���ӣ���ʲôҲû��������������Ҳû�ˡ�");
	set_inquiry("������" , "�Ұ����ص��ҵĿ������ˡ�");
	
	set("combat_exp", 25000);
	set("shen_type", -1);
	set("chat_chance", 10);
	
	carry_object("wcloth")->wear();
};

virtual char * chat_msg(CChar * me)
{
	switch(random(3))
	{
	case 0:
		return "����˵����ɳ��һ���ӽ���һ���ӣ�����һ����ɳ��һ���ӡ�";
	case 1:
		return "����˵������վ���ҵ�������ø���Ǯ!";
	case 2:
		return "����˵�������Ƕ���ɳĮ�������ӣ���������?";
	}
	
	return "";
}

NPC_END;
