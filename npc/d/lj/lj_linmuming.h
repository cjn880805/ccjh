// lj_linmuming.h ��ĺ��
// dieer 2002-7-31

NPC_BEGIN(CNlj_linmuming);

virtual void create()
{
	set_name("��ĺ��", "lin muming");
	set("title", "��װ");
	set("long", "���˶�ʮ�߰�����ͣ���һ��ʯ��ɫ������ͷ����������ſ�������ľ��ţ�����������Ƥɫ���壬һ��������͸�죬�����쳣��");
	set("gender", "Ů��");
	set("age", 27);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",16);				//������������
	set("per",36);
	
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
