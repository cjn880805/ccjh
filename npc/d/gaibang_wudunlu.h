//wudunlu.h
//code by zwb
//12-16

NPC_BEGIN(CNgaibang_wudunlu);

virtual void create()
{
	set_name("����","wu dun lu");

	set("title", "���������");
	set("gender", "����");
	set("age", 23);
	set("long", "���Ǿ����Ĵ���ӣ���òӢ������һ�������ʵ������ӡ�");
 	set("attitude", "peaceful");
 	set("icon",young_man2);
	
	set("per", 24);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set_inquiry("�ض�","������ʦĸ��");
	set_inquiry("�����","������ʦ����");

	set("hp", 1000);
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	
	set("combat_exp", 80000);
	set("score", 20000);
	 
	set_skill("force", 50);			// �����ڹ�
	set_skill("huntian_qigong", 50);	// ��������
	set_skill("unarmed", 50);		// ����ȭ��
	set_skill("xianglong_zhang", 50);	// ����ʮ����
	set_skill("dodge", 50);			// ��������
	set_skill("xiaoyaoyou", 50);		// ��ң��
	set_skill("parry", 50);			// �����м�
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	
	carry_object("cloth")->wear();
};

NPC_END;

