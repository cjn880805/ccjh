VENDOR_BEGIN(CNPub_mujiang);

virtual void create()
{
	set_name( "ľ��");

	set("icon", smith_boss);
	set("gender", "����" );
	set("age", 32);
	set("long",	"��λľ��������ͷ��������Ϊ��������ע����������̧��ͷ��΢Ц��һ�¡�");
	set("combat_exp", 300);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
	set("attitude", "friendly");
	add_money(100);
	carry_object("cloth")->Do_Action(DO_WIELD);

	carry_good("mujian", 10);
	carry_good("mudao", 10);
	carry_good("mugun", 10);
};
VENDOR_END;
