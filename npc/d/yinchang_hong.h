// yinchang_hong.h

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_hong);

virtual void create()
{
	set_name("��л�", "hong qigong");
	set("nickname", "��ؤ");
	set("gender", "����");
	set("age", 75);
        set("icon",old_man2);

	set("long", "������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ�л���ү�ӡ�");
	set("attitude", "peaceful");
	set("class", "beggar");
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);
	
	set("chat_chance", 1);
	//	set("inquiry", ([
	//		"������" : "����������������",
	//		"ؤ��" : "����������������",
	//		"��ʦ" : "�����ȥ�����ŵ��Ұ��ܶ��³�нš�",
	//	]));
	
	set("hp", 1000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 300);
	
	set("combat_exp", 1000000);
	set("score", 200000);
	set("repute", 100000);
	
	set_skill("force", 150);             // �����ڹ�
	set_skill("huntian_qigong", 150);    // ��������
	set_skill("unarmed", 180);           // ����ȭ��
	set_skill("xianglong_zhang", 180);   // ����ʮ����
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 150);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("staff", 150);             // ��������
	set_skill("dagou_bang", 150);        // �򹷰���
	set_skill("begging", 100);           // �л�����
//	set_skill("checking", 100);          // ����;˵
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou_bang");
	map_skill("staff", "dagou_bang");
	
	create_family("ؤ��", 17, "����");
	
	carry_object("yuzhu_zhang");
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "��л�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������";
	case 1:
		return "��л�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������";
	case 2:
		return "��л��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����";
	}
	return "";
}

NPC_END;
