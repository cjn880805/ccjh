//qing_wen.h
//Lanwood 2000-01-10

SHAOLINQING_BEGIN(CNshaolin_qing_wen);

virtual void create()
{
	set_name("���ű���", "qingwen biqiu");
	set("long",	"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺��������������һϮ�ײ��ڱ����ģ��ƺ������ա�");

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",98);
	set("age", 30);
	set("shen_type", 1);
	set("str", 19);
	set("int", 20);
	set("con", 22);
	set("dex", 21);
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
	set_skill("hand", 35);
	set_skill("fengyun_shou", 35);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("hand", "fengyun_shou");
	map_skill("parry", "fengyun_shou");

	prepare_skill("hand", "fengyun_shou");

	create_family("������", 40, "����");
	carry_object("qing_cloth")->wear();
	set("no_huan",1);
};

SHAOLINQING_END;
