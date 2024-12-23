//zaochongzha.h
//code by zwb
//12-15

NPC_BEGIN(CNpub_zaochongzha);

virtual void create()
{
	set_name("赵崇祚","zhao congzha");

	set("icon", officer);
	set("title", "户部尚书");

	set("gender", "男性");
	set("age", 48);
	set("long","此人穿着破棉袄在钱庄门口来回走动，似乎是有什么难处。");

	add_money(3);
	set("no_talk",1);
	set("no_huan",1);
};

int do_talk(CChar * me, char * ask = NULL)
{
	say("赵崇祚满面通红，拘窘不堪道：“兄弟一生清廉，哪想到今日家中却已无米下炊……”", me);
	SendMenu(me);
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(me->is_busy())
		return notify_fail("你上一个动作还没有完成");
	
	if ( EQUALSTR(ob->querystr("id"), "coin") && ob->query("value") >=5000 )
	{
		if(me->query("zhang/renwu5")==2 && !me->query("zhang/renwu5_ok") && !me->query_temp("zhang/renwu5_22"))
		{
			switch(me->query_temp("zhang/renwu5_220"))
			{
			case 0:
				tell_object(me,"\n$HIC赵崇祚连摆双手，道：“此事万万不可。无论阁下是好心或者歹意，我身居朝廷要职，是万不可接收贿赂，落人以把柄的。”\n");
				me->add_temp("zhang/renwu5_220",1);
				return 0;
			case 1:
				tell_object(me,"\n$HIC你凑身上前，轻道：“不错，在下确有所求。大人只需……”");
				tell_object(me,"$HIC赵崇祚拂袖怒道：“此事休提！否则在下明天的奏折里又会加进一条贿赂官员之罪！”\n");
				me->add_temp("zhang/renwu5_220",1);
				return 0;
			case 2:
				tell_object(me,"\n$HIC你哈哈一笑，高声说道：“大人自是清高廉洁，但却忍心看着家中八十老母，岁余幼子都齐齐饿死不成？");
				tell_object(me,"$HIC当今皇上以孝为本,辅之以仁义治天下。你说有人会相信一个残忍到饿死自己亲母嫡子而不顾的人么！");
				tell_object(me,"$HIC赵崇祚！你充其量不过一沽名钓誉的名利匹夫罢了！”\n");
				tell_object(me,"$HIC赵崇祚一阵茫然，呆立片刻，满面羞红，长久之后，连叹道：“罢了，罢了。阁下骂得极是，在下就收下了。哎……”\n");
				me->delete_temp("zhang/renwu5_220");
				me->set_temp("zhang/renwu5_22",1);
				break;
			}
		
			destruct(ob);
			if(me->query_temp("zhang/renwu5_21") && me->query_temp("zhang/renwu5_22")
				&& me->query_temp("zhang/renwu5_23") && me->query_temp("zhang/renwu5_24"))
			{
				me->set("zhang/renwu5_ok",2);
				me->delete_temp("zhang/renwu5_21");
				me->delete_temp("zhang/renwu5_22");
				me->delete_temp("zhang/renwu5_23");
				me->delete_temp("zhang/renwu5_24");
			}
			return 1;
		}
	}
	return 0;
}
NPC_END;
