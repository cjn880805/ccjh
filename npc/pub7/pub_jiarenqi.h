// pub_jiarenqi.h ������
// dieer 2002-8-5

NPC_BEGIN(CNpub_jiarenqi);

virtual void create()
{
	set_name("������", "jiaren qi");
	set("title", "��ʮ������֮");
	set("gender", "Ů��");
	set("age", 30);
	set("level", 157);

	set("attitude", "peaceful");		//����NPC̬��
	set("icon",5);				//������������
	set("per",30);
//	set("repute", -10000);
	
	set("str", 33);
	set("int", 33);
	set("con", 33);
	set("dex", 33);
	
	set("chat_chance_combat", 10);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("mp_factor", 50);			//����NPC��������
	
	set("combat_exp", 40000000+random(20000000));
	set("score", 6000);
	
	set_skill("force", 350);			// �����ڹ�
	set_skill("bibo_shengong", 350);		// �̲���
	set_skill("finger", 350);			// ����ָ��
	set_skill("tanzhi_shentong", 350);		// ��ָ��ͨ
	set_skill("dodge", 350);			// ��������
	set_skill("anying_fuxiang", 350);		// ��Ӱ����
	set_skill("parry", 350);			// �����м�
	set_skill("hand", 350);			        // �����ַ�
	set_skill("lanhua_shou", 350);			// ������Ѩ��

	map_skill("force", "bibo_shengong");		//����NPC��ǰ�ڹ�Ϊ�̲���
	map_skill("hand", "lanhua_shou");	        //����NPC�Ļ����ַ�װ��������Ѩ��
	map_skill("dodge", "anying_fuxiang");		//����NPC�Ļ�������װ����Ӱ����
	map_skill("parry", "lanhua_shou");		//����NPC�Ļ����м�װ��������Ѩ��
	map_skill("finger", "tanzhi_shentong");		//����NPC�Ļ���ָ��װ����ָ��ͨ

	set("apply/armor", 160);			//����NPC���ӷ�����
	set("apply/damage", 60);			//����NPC���ӹ�����

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
		perform_action("force recover", 0);	//�Զ�����
		break;
	case 5:
		perform_action("force recover", 0);	//�Զ�����
		break;
	}	
	return 0;
}

NPC_END;
