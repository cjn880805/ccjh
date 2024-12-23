// lev1_wuweiyang.h ��ά��
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_wuweiyang);

virtual void create()
{
	set_name("��ά��", "wu weiyang");
	set("title", "�������");
	set("gender", "����");
	set("age", 52);
	set("level", 100);
	set("long", 
		"���������Ƿ�β�����ư���ӣ���������������ϵ�����߸���ͬ��ɫ��˿����ɵ�����������ȥ��������䡣\n");
	set("attitude", "friendly");		//����NPC̬��
	set("icon",19);				//������������
	set("repute", -5000);
	
	set("str", 23);
	set("int", 23);
	set("con", 20);
	set("dex", 21);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("bibo_shengong", 190+random(30));		// �̲���
	set_skill("finger", 190+random(30));			// ����ָ��
	set_skill("tanzhi_shentong", 190+random(30));		// ��ָ��ͨ
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("anying_fuxiang", 190+random(30));		// ��Ӱ����
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("hand", 190+random(30));			        // �����ַ�
	set_skill("lanhua_shou", 190+random(30));			// ������Ѩ��

	map_skill("force", "bibo_shengong");		//����NPC��ǰ�ڹ�Ϊ�̲���
	map_skill("hand", "lanhua_shou");	        //����NPC�Ļ����ַ�װ��������Ѩ��
	map_skill("dodge", "anying_fuxiang");		//����NPC�Ļ�������װ����Ӱ����
	map_skill("parry", "lanhua_shou");		//����NPC�Ļ����м�װ��������Ѩ��
	map_skill("finger", "tanzhi_shentong");		//����NPC�Ļ���ָ��װ����ָ��ͨ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	prepare_skill("finger", "tanzhi_shentong");	//����NPC�Ŀ������
	prepare_skill("hand", "lanhua_shou");
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(6))
	{
	case 0:
		perform_action("hand fuxue", 1);	//������Ѩ��(fuxue�黨��Ѩ)
		break;
	case 1:
		perform_action("finger hui", 1);	//��ָ��ͨ���лӳⷽ��
		break;
	case 2:
		perform_action("finger jinglei", 1);	//��ָ��ͨ���е�ָ����
		break;
	case 3:
		perform_action("force powerup", 0);	//�Զ�����
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