NPC_BEGIN(CNPub_oscar);

virtual void create()
{
	set_name("�ӻ�ΰ","oscar");

	set("icon", boy2);
	set("nickname", "�Ժ���");
	set("gender", "����");
	set("age", 20);
	set("long","�����ǹԺ��ӡ�");

	carry_object("jinduan")->wear();

};


NPC_END;
