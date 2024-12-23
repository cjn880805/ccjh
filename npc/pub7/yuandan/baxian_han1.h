//pub_hanxiangzi.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_hanxiangzi);

void create()
{
	set_name("韩湘子", "han xiang zi");
	
	set("title", "八洞神仙");
	set("long","唐人韩文公之侄子也。有道是生有仙骨，索性不羁，厌繁华浓丽，喜恬淡清幽，佳人美女，不能荡其心，美酒甘肴，不能溺其志。");
	
	set("icon", young_man4);
	set("per",23);
	
	set("gender", "男性");
	set("level", 300);
	set("age", 2000);
	set("no_huan",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	say("韩湘子翩翩施礼道：“节日快乐！”",me);	
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	char msg[255];
	if(EQUALSTR(ob->querystr("name"), "玉片") && ob->Query_Amount() ==1
		&& EQUALSTR(ob->querystr("id"), "yu pian") )
	{
		destruct(ob);
		tell_object(me,"\n$HIC湘子略一施礼，鼓笛唱之：");

		tell_object(me,"$HIC青山云水隔，此地是吾家；");
		tell_object(me,"$HIC手扳云霞液，宾晨唱落霞。");
		tell_object(me,"$HIC琴弹碧玉洞，炉炼白朱砂；");
		tell_object(me,"$HIC宝鼎存金虎，芝田养白鸦，");

		tell_object(me,"$HIC一瓢藏造化，三尺新妖邪；");
		tell_object(me,"$HIC解造逡巡酒，能开顷刻花。");
		tell_object(me,"$HIC有人能学我，同共看仙葩。");

		tell_object(me,"\n$HIC湘子取樽至庵前，以金盆盖之。少顷开看，果成美酒。");
		tell_object(me,"$HIC又聚土成堆，不移时开碧花一朵，似牡丹差大，颜色更丽。");
		tell_object(me,snprintf(msg, 255,"$HIC花开拥出金字一行云：“祝%s节日快乐！”\n",me->name(1)));

		return 1;
	}
	if(EQUALSTR(ob->querystr("name"), "玉片") && ob->Query_Amount() >=8
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/han1_liwu") )
	{
		destruct(ob);
		me->set("yuandna/han1_liwu",1);
		tell_object(me,"\n$HIC韩湘子施礼道：“多谢！本仙也有一薄礼相赠！”");
		load_item("greenxiao")->move(me);
		return 1;
	}
	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n向$N看了看，呵呵一笑，“自从渡过东海之后，近千年来我早已不再与人动手了。”", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;
