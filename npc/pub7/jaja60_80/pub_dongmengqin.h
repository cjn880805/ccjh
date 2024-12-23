// lev1_dongmengqin.h ������
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_dongmengqin);

virtual void create()
{
	set_name("������", "dong mengqin");
	set("title", "��Ժ�ϰ�");
	set("gender", "����");
	set("age", 40);
	set("level", 100);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",15);				//������������
	set("repute", -5000);
	
	set("str", 25);
	set("int", 21);
	set("con", 20);
	set("dex", 20);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("kurong_changong", 190+random(30));			// ��������
	set_skill("strike", 190+random(30));			// �����Ʒ�
	set_skill("wuluo_zhang", 190+random(30));			// ����������
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("shenxing_baibian", 190+random(30));		// ���аٱ�
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("sword", 190+random(30));		        // ��������
	set_skill("songshan_sword", 190+random(30));		// ��ɽ����

	map_skill("force", "kurong_changong");		//����NPC��ǰ�ڹ�Ϊ��������
	map_skill("sword", "songshan_sword");	        //����NPC�Ļ�������װ����ɽ����
	map_skill("dodge", "shenxing_baibian");		//����NPC�Ļ����Ṧװ�����аٱ�
	map_skill("parry", "songshan_sword");		//����NPC�Ļ����м�װ����ɽ����
	map_skill("strike", "wuluo_zhang");		//����NPC�Ļ����Ʒ�װ������������

	prepare_skill("strike", "wuluo_zhang");		//����NPC�Ŀ�����ȫ	

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	carry_object("zheshan")->wield();	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
			//�Զ�����
		break;
	case 1:
			//�Զ�����
		break;
	case 2:
			//�Զ�����
		break;
	case 3:
			//�Զ�����
		break;
	case 4:
			//�Զ�����
		break;
	case 5:
			//�Զ�����
		break;
	}	
	return 0;
}

LEV1_END;