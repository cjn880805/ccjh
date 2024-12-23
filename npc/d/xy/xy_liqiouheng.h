//xy_liqiouheng.h 李秋痕（少年）
//秦波 2002、12、12

NPC_BEGIN(CNxy_liqiouheng);

virtual void create()
{    
    set_name("李秋痕", "li qiou heng");
    set("long","她身着一袭淡黄绸衫，肤如凝脂，眉目如画，当真仪态万方，言笑之间，一股娇媚之态自然而生。");	
    set("gender", "女性"); 
    set("age", 20);

    set("str", 20); 
    set("int", 20);
    set("con", 28);
    set("dex", 30);
    set("per", 40);

    set("icon",6);
	set("title","逍遥派");
	create_family("逍遥派", 1, "弟子");

    set("max_hp", 18000);
    set("mp", 9000);
    set("max_mp", 9000);
    set("mp_factor", 120); 
    set("combat_exp", 5000000); 

	set("chat_chance", 30);
	
	set("no_kill",1);

    set_skill("force", 300);
    set_skill("xiaowuxiang", 300);
    set_skill("dodge", 300);
    set_skill("xiaoyao_bu", 300);
    set_skill("unarmed", 300);
    set_skill("liuyang_zhang", 300);
    set_skill("parry", 300);
    set_skill("blade", 300);
    set_skill("xiaoyao_dao", 300);
    set_skill("zhemei_shou", 300);
    set_skill("hand", 300);
	set_skill("literate", 280);
    
    map_skill("force", "xiaowuxiang");
    map_skill("dodge", "xiaoyao_bu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("gangdao")->wield();
	set("no_huan",1);

}

virtual int do_look(CChar * me)
{
	if(me->query("xy/renwu8_1") )
	{
		say("只见她脸上纵横交错，四条极长的剑伤划成了一个“井”字。由于这四道剑伤，右眼突出，左边嘴角斜歪，说不出的丑恶难看。", me);
		SendMenu(me);
		return 1;
	}
	
	return CChar::do_look(me);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if((EQUALSTR((me->environment())->querystr("base_name"), "逍遥谷小屋" )))
	{
		if(me->query("xy/renwu4_3") && ! me->query("xy/renwu4_61"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("邀请共同夺宝","duobao",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "duobao") )
			{
				say("你向李秋痕说道：“弟子欲前往四象塔夺宝，但因功力尚浅，恐力所不能及，不知师叔可否相助？”",me);
				if((!me->query("xy/renwu4_4") ||me->query("xy/renwu4_4")==2 ) &&!me->query_temp("xy/renwu4_1"))
				{
					say("李秋痕说道：“好吧，我便陪你去一趟！”",me);
					tell_object(me,"$HIC李秋痕决定开始跟随你行动。");
					set_leader(me);
					set("owner",atoi(me->id(1)));
					me->set_temp("xy/renwu4_1",2);//邀请李秋痕成功1、天山铁姥 2、李秋痕
					if(!me->query("xy/renwu4_4"))
						me->set("xy/renwu4_4",2);	//邀请李秋痕前去夺宝：1、天山铁姥 2、李秋痕
				}
				else if(me->query_temp("xy/renwu4_1"))
				{
					say("李秋痕皱了皱眉头。",me);
				}
				else
				{
					say("李秋痕说道：“师姐本事那么大，有她帮你，那还来请我做什么呀！”",me);
				}
				SendMenu(me);
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual char * chat_msg()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",query("owner"));
		me=find_online(msg);
		if(!me)
		{
			destruct(this);
		}
		else if(me->query("xy/renwu4_4")==2 && me->query_temp("xy/renwu4_1")==2)
		{
			
			if(me->query_temp("fight/is_fighting") 
				&& EQUALSTR(((me->environment())->environment())->name(1),(environment())->name(1)))
			{
				int team;
				CFightRoom * obj=(CFightRoom *)me->environment();
				if(me->query_temp("fight/fight_team"))		//加入A队
					team = 1;
				else
					team = 0;
				move(obj);
				obj->Join_Team(this, team);
			}
		}
		else
		{
			destruct(this);
		}
	}
	return 0;
}

virtual void die()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",query("owner"));
		me=find_online(msg);
		if(me)
		{
			if(me->query("xy/renwu4_4")==2 && me->query_temp("xy/renwu4_1")==2)
			{
				me->delete_temp("xy/renwu4_1");
			}
		}
	}
	CNpc::die();
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "青龙书生袍") && EQUALSTR(ob->querystr("base_name"), "qinglong_pao") 
		&& me->query("xy/renwu4_61") && !me->query("xy/renwu4_63") && me->query("xy/renwu4_4")==2
		&&!me->query("xy/renwu5"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
		{
			tell_object(me,"\n$HIR李秋痕双手轻扶衣襟，凤眼向你一瞟，微笑首说道：“师侄有心了，妾身无以为报，就授你一式六阳掌吧！”");
			tell_object(me,"\n$HIR你倾听着李秋痕讲解“六阳掌”的精要所在，对“六阳掌”有了更深一层次的理解。");
			switch(random(3))
			{
			case 0:
				me->add("skill_pro/灵鹫宫/六阳掌/force",1);
				tell_object(me,"$HIR你的六阳掌配合内功更能融汇贯通了。\n");
				break;
			case 1:
				me->add("skill_pro/灵鹫宫/六阳掌/dodge",1);
				tell_object(me,"$HIR你的六阳掌使用得更加得心应手了。\n");
				break;
			case 2:
				me->add("skill_pro/灵鹫宫/六阳掌/damage",1);
				tell_object(me,"$HIR你的六阳掌威力更大了。\n");
				break;
			}
		}
		else
		{
			tell_object(me,"\n$HIR李秋痕双手轻扶衣襟，凤眼向你一瞟，微笑首说道：“师侄有心了，妾身无以为报，就指点你几式武功吧！”");
			tell_object(me,"你倾听着李秋痕的讲解，对武学进境有了更深一层次的理解,从中领悟了1000点的经验。！");
			me->add("combat_exp",1000);
			me->UpdateMe();
		}
		me->set("xy/renwu4_63",1);//青龙书生袍送给李秋痕
		me->set("xy/renwu5",1);//逍遥任务任务第五部分：争夺琅擐福地
		destruct(ob);
		return 1;
	}

	return 0;
}

NPC_END;




