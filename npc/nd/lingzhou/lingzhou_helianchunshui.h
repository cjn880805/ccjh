//helianchunshui.c �����õĻ���
//sound 2001-07-17

NPC_BEGIN(CNlingzhou_helianchunshui);

virtual void create()
{
	set_name( "�����ﲨ" , "helian chunshui");
	set("gender", "����" );
	set("age", 29 );
	set("long",
		"�����ﲨ��һƷ����������ͭ����ֶ�ӣ����ʴ�ӱ��ʮ����ʱ����\n"
		"���˼Ҵ���������ǹ���ľ��衣������Ц��������ν���������\n"
		"��ͳ������������Ϊ����������ͷ����ǹ���У��������ǹ������\n"
		"ǹ�����е����С�������ǹ���ۣ����Ĳ����ڶ����룬�˳ơ���ǹ\n"
		"С��ү��������ͨ������ԭ��������Ȼ����һƷ������һ���ĵ�\n"
		"һ���֡�\n");
	
	set("str", 33 );
	set("cor", 34 );
	set("int", 43 );
	set("per", 33 );
	set("dex", 25 );
	set("con", 30 );
	set("icon",general);
	
	set("force", 1500); 
	set("max_force", 1500); 
	set("mp_factor", 100);
	
	set_skill("yanxing_dao", 140);
	set_skill("fuhu_quan", 120);
	set_skill("duanshi_xinfa", 60);
	set_skill("dodge", 1300);
	set_skill("unarmed", 1500);
	set_skill("long", 2000);
	set("combat_exp", 30000);
//	set("social_exp", 50000);
	
//	carry_object("baizhu_sipao")->wear();
//	carry_object("kaijia1")->wear();
//	carry_object("zhanpao")->wear();
//	carry_object("qiang")->wield();
//	JoinZuzhi("yipin", "��������", "������");
}
/*
int welcome_visitor( object me )
{
	object npc = this_object(), cloth, ling;
	
	foreach( object inv in deep_inventory( me ) )
	{
		if ( ( inv->name() == "$YEL������$COM" ) && inv->id( "ling pai" ) )
			ling = inv;
		if ( ( inv->name() == "�ſ�" ) && inv->id( "hao kan" ) )
			cloth = inv;
	}
	
	if ( !cloth && !ling )
	{
		message_vision( "$CYN$N����$nһ�ۣ��ȵ��������´���ɱ�ˣ�Ī�ǵ��Ҵ��������𣿣���$COM\n", npc, me );
		kill_ob( me );
	}
}

int refuse_killing( object me )
{
	set("force_factor", 100);
	return 0;
}

int accept_fight( object me )
{
	if ( me->ZuzhiTouxianJibie("yipin") < 6 )
	{
		message_vision( "$CYN$N�����һ�ۣ��������Һ�æ����ȥ����Щ��ʿ�ɡ���$COM\n",
			this_object() );
		return 0;
	}
	else
	{
		message_vision( "$CYN$N����$nһ�ۣ���ɫ��Ȼ��䣺���ף�����ʲô�ˣ�"
			"��ô�������ģ���$COM\n" 
			,this_object() ,me);
		kill_ob( me );
		return notify_fail("");
	}
}

int valid_teach( object me, string skill )
{
	return 0;
}
*/
NPC_END;