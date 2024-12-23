//qing_xiao.h
//Lanwood 2000-01-10

SHAOLINQING_BEGIN(CNshaolin_qing_xiao);

virtual void create()
{
	set_name("��������", "qingxiao biqiu");
	set("long",	"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺��������������һϮ�ײ��ڱ����ģ��ƺ������ա�");
	
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",100);
	set("age", 30);
	set("shen_type", 1);
	set("str", 23);
	set("int", 21);
	set("con", 18);
	set("dex", 22);
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
	set_skill("claw", 35);
	set_skill("longzhua_gong", 35);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("claw", "longzhua_gong");
	map_skill("parry", "longzhua_gong");

	prepare_skill("claw", "longzhua_gong");

	create_family("������", 40, "����");
    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};

SHAOLINQING_END;
