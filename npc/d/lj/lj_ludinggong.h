// lj_ludinggong.h ¹����
// dieer 2002-7-31

NPC_BEGIN(CNlj_ludinggong);

virtual void create()
{
	set_name("¹����", "luding gong");
	set("long", "��ͷ���춥����������ӣ�ü����Ц����߯���⣬������ҡ���ȣ��������֮�������ֵ��ϴ󵶣�ٲȻ����֮��������Τ��С����Ҳ��");
	set("gender", "����");
	set("age", 21);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",17);				//������������
	set("per",20);
	
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
