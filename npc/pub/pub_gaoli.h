// pub_gaoli.c
//code by Fisho
//date : 2000-12-14
//inherit F_VENDOR;
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_gaoli);

virtual void create()
{
	set_name("������","gaoli shang" );

	set("icon", pawnshop_boss);
	set("title", "���޷��ϰ�");
	set("shen_type", 1);
	
	set("gender", "����");
	set("age", 45);
	set("long",		"���Ǹ��������ˣ����ú��й���ûɶ���������Ķ���Ҳ��ࡣ");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);
	
	set("combat_exp", 40000);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();
//	carry_good("mabudai",500);
	carry_good("beixin",500);
	carry_good("toukui",500);
	carry_good("cycle",500);
	carry_good("surcoat",500);
	carry_good("shield",500);
	carry_good("huwan",500);
	carry_good("zhitao",500);
	carry_good("huyao",500);
	carry_good("caoxie",500);
	carry_good("pixue",500);
	carry_good("shoutao",500);
	carry_good("tieshou",500);
	carry_good("jinsijia",500);
//	carry_good("fire",500);
}

VENDOR_END;