//qing_guan.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_qing_guan);

virtual void create()
{
	set_name("��۱���", "qingguan biqiu");
	set("long",	"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺��������������һϮ�ײ��ڱ����ģ��ƺ������ա�");
	
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",110);
	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 15);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 1050);
	
	set("mp", 350);
	set("max_mp", 350);
	set("mp_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin_shenfa", 30);
	set_skill("strike", 30);
	set_skill("sanhua_zhang", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "sanhua_zhang");
	map_skill("parry", "sanhua_zhang");

	prepare_skill("strike", "sanhua_zhang");

	create_family("������", 40, "����");
    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};


NPC_END;
