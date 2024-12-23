//lingjiu_wulaoda.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_wulaoda);

virtual void create()
{
	set_name("白老三",  "wu laoda");
	set("long","他就是名动江湖的白老三，由于谋反铁姥未遂而被囚禁于此。");
	set("gender", "男性");
	//	set("title", "西夏一品堂高手");
	//	set("nickname",  "斩红郎无霜剑" );
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");
 	set("icon",old_man2);
	
	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);
	
	set("max_hp", 3000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 0l);
	
	set("combat_exp", 1000000);
	set("score", 100000);
	set("chat_chance", 3);
	set("wan_count", 1);
	
	set_inquiry("白云熊胆丸",ask_me);
	
}

virtual char * chat_msg()
{
	return "白老三喃喃道：白云熊胆丸可真是好东西！";
}	

static char * ask_me(CNpc *who,CChar *me)
{
	CContainer *obj;
	if (!(me->querymap("family")) || DIFFERSTR(me->querystr("family/family_name"), "灵鹫宫"))
		//return query_respect(me) + "你怎敢要灵鹫宫之镇派宝物呢？");
		return "你怎敢要灵鹫宫之镇派宝物呢？";
	
	if (who->query("wan_count") < 1)
		return "不好意思，已经有人捷足先登了，你下次再来吧。";
	who->add("wan_count", -1);
	obj = load_item("baiyunwan");//白云熊胆丸
	obj->move(me);
	return "唉，看在你舍身救我的份上，这颗白云熊胆丸就给你吧。";
}

NPC_END;