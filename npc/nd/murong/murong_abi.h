// abi.c ����
//sound 2001-07-16

NPC_BEGIN(CNmurong_abi);

virtual void create()
{
	set_name("����", "a bi");
	set("gender", "Ů��");
	set("age", 20);      
	set("title","����Ѿ��");
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("per", 30);
	set("icon",young_woman9);

	set("combat_exp", 13000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("hp",1000);
	set("max_hp",1000);
	set("mp",1000);
	set("max_mp",1000);
	set("mp_factor",30);
	set("score", 8000);
	
	set_skill("cuff", 50);
	set_skill("parry",40);
	set_skill("yanling_shenfa",70);
	set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan_gong",70);
	
	map_skill("force","shenyuan_gong");
	map_skill("dodge","yanling_shenfa");
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	
	carry_object("shoe")->wear();
//	carry_object("red_silk")->wear();
//	carry_object("skirt1")->wear();
	
	set_inquiry("����", "����Ľ�ݹ��ӵ�����Ѿ�ߣ��������̣��þ�û�м���Ľ�ݹ����ˡ�");
	set_inquiry("����", "����������ˮ鿣���Ľ����үΪ���չ��Ҹ��Ұ��ŵ�ס����");
	set_inquiry("����",  "��٢��ɽׯ������ĸ��һ���Ӳ�������ȥ����ɽׯ�������Ƕ����ҡ�");
	set_inquiry("��٢��ɽׯ",  "�����ﲻԶ����һС����Ϊ����ӣ�ֻҪ�������ң��Ϳɳ˴�ǰ����");
	set_inquiry("Ľ�ݸ�", "Ľ���ظ�����������������ˣ����Ա�֮������ʩ���������������");
	set_inquiry("�����", "˳��С��һֱ�����ߣ�����������ˡ�");	
}

NPC_END;