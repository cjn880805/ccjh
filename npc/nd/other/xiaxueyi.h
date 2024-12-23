// xiaxueyi.h ��ѩ��
//by sound 2001-07-10

NPC_BEGIN(CNxiaxueyi);

virtual void create()
{
	set_name("��ѩ��", "xia xueyi");
	set("nickname", "�����ɾ�");
	set("gender", "����");
	set("age", 40);
	set("long", 
		"��ѩ������Ź֣�Ϊ�����ݣ��书���������˰�����Ѳ⡣\n"
		"������������������Ϊ֮ɫ�䣬���ǳ������Ѳ����\n");

	set("attitude", "aggressive");		//����NPC̬��
	set("icon",young_man6);			//������������
	
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);			//�����Զ����촥����
	set("chat_chance_combat", 50);		//����NPCʹ�þ��еļ���
	
	set_inquiry("�κ�ҩ", "�ȣ��Ǹ������ж����ң����Ҳ�������");
	set_inquiry("����", "��������ˣ������ڿɺã�");
	set_inquiry("�¼�����", "�Һ޲��ÿ����������ǵ��⣬�����ǵ�Ѫ�������ǵ�Ƥ��");
	set_inquiry("Ԭ��־", "�����ҵ�С�ֵܣ��˳��Ĺ�˧��");
	set_inquiry("�����ؼ�", "��Ҵ����ؼ������⣬������ˣ�");
	
	set("hp", 6000);
	set("max_hp", 6000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 400);
	
	set("combat_exp", 6000000);
	set("score", -500000);
	 
	set_skill("force", 250);			// �����ڹ�
	set_skill("wudu_shengong", 250);	// �嶾��
	set_skill("unarmed", 250);			// ����ȭ��
	set_skill("sword", 250);			// ��������
	set_skill("jinshe_zhang", 250);		// ����������
	set_skill("jinshe_jian", 250);		// ���߽���
	set_skill("throwing", 250);			// ����Ͷ��
	set_skill("jinshe_zhui", 250);		// ����׶��
	set_skill("dodge", 250);			// ��������
	set_skill("guimei_shenfa", 250);	// ������
	set_skill("parry", 250);			// �����м�
	
	map_skill("force", "wudu_shengong");		//����NPC��ǰ�ڹ�Ϊ�嶾��
	map_skill("unarmed", "jinshe_zhang");		//����NPC�Ļ���ȭ��װ������������
	map_skill("throwing", "jinshe_zhui");			//����NPC�Ļ���Ͷ��װ������׶��
	map_skill("dodge", "guimei_shenfa");		//����NPC�Ļ����Ṥװ��������
	map_skill("parry", "jinshe_jian");			//����NPC�Ļ����м�װ�����߽���

	carry_object("jinshe_jian")->wield();
	carry_object("jinshe_zhui")->wield();
}

virtual char * chat_msg()		//NPC�Զ�����
{
	switch(random(2))
	{
	case 0:
		return 	"��Ҫ������һ��Ҫ���¼�������ϼһﱨ��";
	case 1:
		return 	"�������ڹ��Ŀɺã�����ĺ�����������ʵ��̫�������ˡ�";
	}

	return 0;
}

virtual char * chat_msg_combat()	//NPC�Զ�������
{
	switch(random(4))
	{
	case 0:
		perform_action("sword suo", 1);			//���߽����ľ���
		break;
	case 1:
		perform_action("unarmed fugu", 1);		//���������Ƶľ���
		break;
	case 2:
		perform_action("throwing tuwu", 1);		//�����Ƶľ���
		break;
	case 3:
		perform_action("force recover", 0);		//�Զ�����
		break;
	}

	return 0;
}

NPC_END;
