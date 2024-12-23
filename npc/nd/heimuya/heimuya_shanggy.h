//heimuya_shanggy.h 上官云
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_shanggy);

virtual void create()
{
	set_name("上官风", "shangguan yun");
	set("gender", "男性" );
	set("age", 40);
	set("title" , "日月神教白虎堂长老");
	set("long", "他长手长脚, 双目精光灿然, 若有威势。");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 30);
 	set("icon",young_man5);

	set("hp",800);
	set("max_hp", 800);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 200);
	set("combat_exp", 360000);
	set("score", 30000);

	set_skill("force", 80);
	set_skill("dodge", 120);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("staff",100);
	set_skill("hamagong",70);
	set_skill("chanchu_bufa", 120);
	set_skill("lingshe_zhangfa", 100);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");

	create_family("日月神教",2,"弟子 白虎堂长老");

	set("chat_chance", 3);
	
	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
//	carry_object("zhenzhu")->wear();
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * me)
{
	say("我是患难之身, 怎么能收徒呢。壮士还是请回吧!", me);
	SendMenu(me);
}

virtual int accept_object(CChar * me, CContainer * obj)
{
	if(me->query_temp("ry/renwu3_1") && !me->query_temp("ry/renwu3_2"))
	{
		if (obj->query("ry/heimu_ling") &&  EQUALSTR(obj->querystr("owner1"), me->id(1)))
		{
			say( "上官风道“好！现在咱们来对一下口令，如果答对我就送你上去！”", me);
			me->set_temp("ry/renwu3_2",1);//上官风接受黑木令，准备对口令
			destruct(obj);
			SendMenu(me);
			return 1;
		}
	}
	else  
    {
		message_vision("上官风对$N说：你敢耍我？！\n", me);
        this->kill_ob(me);
    }
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("ry/renwu3_2") && !me->query_temp("ry/renwu3_3"))
	{
		if(! strlen(ask))
		{
			say("上官风问道：“文成武德、仁义英明教主宝训第三条：对敌须狠，”",me);
			AddMenuItem("斩草除根，男女老幼，不留一人","one",me);
			AddMenuItem("斩草除根，男女老幼，全部不留","two",me);
			AddMenuItem("斩尽杀绝，男女老幼，不留一人","three",me);
			AddMenuItem("斩草除根，男女妇孺，不留一人","four",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "one") )
		{
			tell_object(me,"\n$HIR上官风道“嗯！口令没问题，你可以上去了！”");
			tell_object(me,"\n$HIC上官风一招手，只见天际之中缓缓放下一只大吊篮，足可装得十来石米。");
			tell_object(me,"$HIC上官风喝道：“请这位英雄上去。”");
			tell_object(me,"$HIC你跨进一弯腰进了吊篮。");
			tell_object(me, "\n$HIC铜锣三响，吊篮缓缓升高。原来上有绞索绞盘，将竹篓绞了上去。");
			tell_object(me, "$HIC吊篮不住上升，你抬头上望，只见头顶有数点火星，这黑木崖着实高得厉害。你不由得伸出右手，握住了绳子。");
			tell_object(me, "$HIC黑夜之中，仍可见到一片片轻云从头顶飘过，再过一会，身入云雾，俯视篮底，但见黑沉沉的一片，连灯火也望不到了。");
			
			me->set_temp("ry/renwu3_3",1);//对完口号，开始上崖
			call_out(goto_heimuya, 10,me->object_id());
		}
		else if(!strcmp(ask, "two") ||!strcmp(ask, "three") ||!strcmp(ask, "four") )
		{
			message_vision("上官风对$N说：大胆狂徒，居然敢来日月神教蒙混，早死！\n", me);
			this->kill_ob(me);
			me->delete_temp("ry");
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

static void goto_heimuya(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env = ob->environment();
	CChar * me =  (CChar *)env->Present(param1);
	if(me)
	{
		tell_object(me, "\n$HIC过了良久，吊篮才停。上官云陪陪着你踏出吊篮。\n");
		me->move (load_room("黑木崖顶通道1层"));
		tell_object(me, "\n$HIR没想到刚一踏出吊篮上官云就喝道:“各位给我抓住这小子，他拿了早已做废的黑木令，还想混进崖来！”\n");
		me->set_temp("ry/renwu4_1",1);//开始勇闯黑木崖顶
	}
}

NPC_END;