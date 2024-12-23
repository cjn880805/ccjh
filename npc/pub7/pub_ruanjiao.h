// pub_ruanjiao.h ����
//jaja 2002-10-20

NPC_BEGIN(CNpub_ruanjiao);

virtual void create()
{
	set_name("����", "ruan jiao");
	set("title", "ˮ��");
	set("gender", "����");
	set("age", 31);
	set("level", 100);
	set("long", 
		"���������������Ĳ��ߣ���ֱ��˵����С�ݸɣ����ϻ�һ�飬��һ�飬�·��������İ�Ѣ��һ˫�۾���Ҳ�����˺�˿��ȫ����ɡ�\n");
	set("attitude", "peaceful");		//����NPC̬��
	set("icon",14);				//������������
	set("repute", 4000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 30);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 250);			// �����ڹ�
	set_skill("shedao_qigong", 250);		// �ߵ�����
	set_skill("shenlong_xinfa", 250);		// �����ķ�
	set_skill("dodge", 250);			// ��������
	set_skill("yixingbu", 250);			// ���β�
	set_skill("shenlong_bashi", 250);		// ������ʽ
	set_skill("parry", 250);			// �����м�
	set_skill("strike", 250);		        // �����Ʒ�
	set_skill("huagu_mianzhang", 250);		// ��������

	map_skill("force", "shenlong_xinfa");		//����NPC��ǰ�ڹ�Ϊ�����ķ�
	map_skill("strike", "huagu_mianzhang");	        //����NPC�Ļ����Ʒ���װ����������
	map_skill("dodge", "yixingbu");			//����NPC�Ļ����Ṥװ�����β�
	map_skill("parry", "shenlong_bashi");		//����NPC�Ļ����м�װ��������ʽ

	prepare_skill("strike", "huagu_mianzhang");	//����NPC��ǰʹ�õļ���Ϊ�Ʒ����

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 30);			//����NPC���ӹ�����
	
}


virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(3))
	{
	case 0:
		perform_action("parry yingxiong", 1);	//Ӣ����ʽ
		break;
        case 1:
		perform_action("force recover", 0);	//�Զ�����
		break;
        case 2:
		perform_action("force recover", 0);	//�Զ�����
		break;
	}	
	return 0;
}

NPC_END;
