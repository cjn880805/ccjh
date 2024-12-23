//xy_licanghai1.h 李沧海（少年）
//秦波 2002、12、12

NPC_BEGIN(CNxy_licanghai1);

virtual void create()
{    
    set_name("李沧海", "li cang hai");
    set("long","她年岁不大，容貌与李秋痕非常相似，只是她的眼旁多了一颗小小黑痣，微笑之中，嘴角露出两个浅浅的酒窝，别有一番清纯可爱之美。");	
    set("gender", "女性"); 
    set("title","逍遥派");
	set("age", 14);

    set("str", 16); 
    set("int", 16);
    set("con", 30);
    set("dex", 30);
    set("per", 40);
    set("icon",5);
	create_family("逍遥派", 1, "弟子");

    set("max_hp", 10000);
    set("mp", 5000);
    set("max_mp", 5000);
    set("mp_factor", 30); 
    set("combat_exp", 500000); 
	
	set("no_kill",1);

    set_skill("force", 100);
    set_skill("beiming_shengong", 100);
    set_skill("dodge", 100);
    set_skill("lingboweibu", 100);
    set_skill("unarmed", 100);
    set_skill("liuyang_zhang", 100);
    set_skill("parry", 100);
    set_skill("blade", 100);
    set_skill("xiaoyao_dao", 100);
    set_skill("hanzhemei_shoud", 100);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 100);
    set("apply/damage", 50);
    carry_object("gangdao")->wield();

	set("chat_chance", 30);
	set("no_huan",1);
	set("no_kill",1);

}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "白虎绝尘靴") && EQUALSTR(ob->querystr("base_name"), "baihu_xue") 
		&& me->query("xy/renwu4_5") && !me->query("xy/renwu4_64") &&!me->query("xy/renwu6"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
		{
			tell_object(me,"\n$HIR李沧海嘻嘻笑道：“我要是穿了这鞋子，定能捉住不少蝴蝶哩！”");
		}
		else
		{
			tell_object(me,"\n$HIR李沧海嘻嘻笑道：“嘻嘻，谢谢你呀，听说大师兄要教你逍遥剑法呢，这把剑送给你用吧！”");
			load_item("sword_3")->move(me);
		}
		me->set("xy/renwu4_64",1);//白虎绝尘靴送给李沧海
		destruct(ob);
		return 1;
	}
	return 0;
}

virtual char * chat_msg()
{
	if(querystr("owner")[0])
	{
		CContainer * env = environment();
		CContainer * xiaoyaozi=env->present(querystr("owner"));
		if(!xiaoyaozi)
		{
			add("waring",1);
			if(query("waring")>2)
				destruct(this);
		}
		else
			del("waring");
	}
	return 0;
}

NPC_END;




