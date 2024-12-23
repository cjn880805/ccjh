// lev1_qiufengcheng.h ����
// jaja 2002-12-6

LEV1_BEGIN(CNlev1_qiufengcheng);

virtual void create()
{
	set_name("����", "qiu fengcheng");
	set("title", "��ǹ����");
	set("gender", "����");
	set("age", 26);
	set("level", 100);
	set("long", 
		"�����ᡢ�������ߴ�Ӣ����������һ�ֽ������õ����ʡ������ϴ�����һϮ��ֵǧ������ã��������Ź⻪��Ŀ����ǹ��ǹ���Ǵ����ġ�\n");
	set("attitude", "friendly");		//����NPC̬��
	set("icon",18);				//������������
	set("repute", 3000);
	
	set("str", 23);
	set("int", 21);
	set("con", 21);
	set("dex", 22);
	
	set("chat_chance_combat", 5);		//����NPCʹ�þ��еļ���
		
	set("max_hp", 10000);
	set("max_mp", 5000);
	set("mp_factor", 1);			//����NPC��������
	
	set("combat_exp", 1800000+random(300000));
	set("score", 6000);
	
	set_skill("force", 190+random(30));			// �����ڹ�
	set_skill("kurong_changong", 190+random(30));		// ��������
	set_skill("unarmed", 190+random(30));			// ����ȭ��
	set_skill("changquan", 190+random(30));		// ��ȭ
	set_skill("dodge", 190+random(30));			// ��������
	set_skill("shenxing_baibian", 190+random(30));		// ���аٱ�
	set_skill("parry", 190+random(30));			// �����м�
	set_skill("club", 190+random(30));		        // ��������
	set_skill("zhongpingqiang", 190+random(30));		// ��ƽǹ��

	map_skill("force", "kurong_changong");		//����NPC��ǰ�ڹ�Ϊ��������
	map_skill("club", "zhongpingqiang");	        //����NPC�Ļ�������װ����ƽǹ��
	map_skill("dodge", "shenxing_baibian");		//����NPC�Ļ����Ṧװ�����аٱ�
	map_skill("parry", "zhongpingqiang");		//����NPC�Ļ����м�װ����ƽǹ��
	map_skill("unarmed", "changquan");		//����NPC�Ļ���ȭ��װ����ȭ

	set("apply/armor", 100);			//����NPC���ӷ�����
	set("apply/damage", 10);			//����NPC���ӹ�����

	carry_object("doupeng");	
	carry_object("changqiang")->wield();	
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