// lj_miaorenhuang.h ���˻�
// dieer 2002-7-31

NPC_BEGIN(CNlj_miaorenhuang);

virtual void create()
{
	set_name("���˻�", "miao renhuang");
	set("title", "�����");
	set("long", "���������ָ����ݣ������л��������޵�ʧ��������֮�飬�ƺ���ȫ���˵����������޵��ֳ��������");
	set("gender", "����");
	set("age", 42);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",16);				//������������
	set("per",25);
	
	set("str", 41);
	set("int", 47);
	set("con", 42);
	set("dex", 41);
	
	set("combat_exp", 5000000);
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("no_kill",1);
}

NPC_END;
