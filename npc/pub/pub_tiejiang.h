VENDOR_BEGIN(CNPub_tiejiang);

virtual void create()
{
	set_name( "����");

	set("icon", smith_boss);
	set("title", "�������ϰ�");
	set("shen_type", 1);

	set("gender", "����" );
	set("age", 33);
	set("long", "��λ�������ڶ��������ش���������������ע����������̧��ͷ��΢Ц��һ�¡�");

	set("combat_exp", 400);
	set("attitude", "friendly");
	carry_object("cloth")->Do_Action(DO_WIELD);

	carry_good("gangdao", 100);
	carry_good("changjian", 100);
	carry_good("qimeigun", 100);
	carry_good("changbian", 100);
	carry_good("gangzhang", 100);
	carry_good("tiejia", 100);
	carry_good("sword_1", 100, 1);
	carry_good("sword_1", 100, 2);
	carry_good("sword_1", 100, 3);
	carry_good("sword_1", 100, 4);
	carry_good("sword_1", 100, 5);
	carry_good("sword_2", 100, 1);
	carry_good("sword_2", 100, 2);
	carry_good("sword_2", 100, 1);
	carry_good("blade_1", 100, 1);
	carry_good("blade_1", 100, 2);
	carry_good("blade_1", 100, 3);
	carry_good("blade_1", 100, 4);
	carry_good("blade_1", 100, 5);
	
};
VENDOR_END;
