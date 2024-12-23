//dao_pin.h
//Lanwood 2000-01-10

SHAOLINDAO_BEGIN(CNshaolin_dao_pin);

virtual void create()
{
	set_name("��Ʒ��ʦ", "daopin chanshi");
	set("long",	"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ��У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�");

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
set("foolid",83);
	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 18);
	set("con", 20);
	set("dex", 23);
	set("max_hp", 1200);
	
	set("mp", 450);
	set("max_mp", 450);
	set("mp_factor", 40);
	set("combat_exp", 10000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("finger", 51);
	set_skill("nianhua_zhi", 51);
	set_skill("blade", 54);
	set_skill("cibei_dao", 54);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("blade", "cibei_dao");
	map_skill("parry", "cibei_dao");

	prepare_skill("finger", "nianhua_zhi");

	create_family("������", 39, "����");
	set_inquiry("ľ����","����Ϣ������ľ����ȫ������Ϊľ�ˣ��������桭�������������Ȱ�ͭ������ҡ�");

    carry_object("jiedao")->wield();
    carry_object("xu_cloth")->wear();
	set("no_huan",1);
};


int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "cibei ling"))
		return CNshaolin_dao::accept_object(who, ob);		//lanwood 2001-04-13 ��Ȼ������սʦ���ˡ�

/*
	if( DIFFERSTR(who->querystr("family/family_name"), "������"))
		return notify_fail("���뱾��������������֪�˻��Ӻ�̸��");
*/
	if ( DIFFERSTR(who->querystr("class"), "bonze"))
		return notify_fail("�����׼ҵ��ӣ�Ҫ��ľ������ʲô�أ�");
	
	if ( current_time <query("passtime") )
	{
		message_vision("��Ʒ��ʦ���������Ѿ������ڹ����ˣ�",who);
		return notify_fail("��Ʒ��ʦ���������Ѿ������ڹ����ˣ�");
	}

	char msg[255];

	set("passtime",current_time + 180);

    message_vision(snprintf(msg, 255, "$N����$n��Ц��һ����������Ȼ������������ɹֲ����ҡ�����"), this, who);
	destruct(ob);
	ob=load_room("������ľ����");
	who->move(ob);

	return 1;
}


SHAOLINDAO_END;




