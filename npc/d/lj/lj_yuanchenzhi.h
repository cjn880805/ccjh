// lj_yuanchenzhi.h Ԭ��־
// dieer 2002-7-31

NPC_BEGIN(CNlj_yuanchenzhi);

virtual void create()
{
	set_name("Ԭ��־", "yuan chenzhi");
	set("long", "����׳��ʵ����ɫ��ڣ�һ˫����ȴ�Ǿ���������������֮�У���Ȼ��¶��һ�����ơ�");
	set("gender", "����");
	set("age", 27);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",17);				//������������
	set("per",25);
	
	set("str", 41);
	set("int", 47);
	set("con", 42);
	set("dex", 41);

	set("combat_exp",3000000);
	
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("no_kill",1);
}

NPC_END;
