#define YEWAIROOM_BEGIN(room_name)	class room_name : public CRyewai_room	{	public:	room_name(){};	virtual ~room_name(){};
#define YEWAIROOM_END		}	

//XuNing 2001-08-31

ROOM_BEGIN(CRyewai_room);

virtual int valid_leave(CChar * me, const char * dir)
{
	if(me->query("level")<80)
	{
		tell_object(me,"以你目前的能力还是不要进去吧，回去吧！");
		me->move(load_room("佛山北帝庙"));
		return 0;
	}
	CDoor *d;
	UINT n;
	
	if((d = PresentDoor(dir)) == 0)return 1;
	
	if(((n = me->query_temp("mapnum")) == 0 || me->query_temp("firstmap") == 1) && !strcmp(me->querystr_temp("todir"), d->querystr("id")))
	{
		CRoom * r = load_room(me->querystr_temp("frommap"));		//读取来时的地图
		if(! r) return 0;
		
		me->set_temp("init_door", me->querystr_temp("fromdir"));
		if(me->move(r))
		{
			me->delete_temp("frommap");
			me->delete_temp("fromdir");
			me->delete_temp("todir");
			me->delete_temp("mapnum");
			me->delete_temp("init_door");
			return 2;						//移动失败且不返回失败信息
		}
		me->delete_temp("init_door");
	}
	else if(n > 0)
	{
		me->set_temp("mapnum", --n);
	}
	
	me->delete_temp("firstmap");
	
	return 1;
}

virtual void ChangeRoom(CContainer * me)
{
/*	tell_object(me, "远方隐约传来大魔王的狂笑。", "tell");

	switch (random(4))//是否触发
	{
	case 0://触发事件
		message_vision ("$N觉得四周空间正在发生异变，但又捉摸不出那里不对。", me);						

		switch (random(9))
		{
		case 0:	//触发事件1，火焰：强烈的伤害
			message_vision ("$RED忽然天色一暗，接着变红，然后无数天火下降，其中有一团火向$N迎面砸来。$COM", me);						
			return 0;

		case 1:	//触发事件2，毒水：持续的伤害
			message_vision ("$RED四周一片锣鼓之声，大量的毒水不断从四面喷来，毒性猛烈，毁金销骨，眼见要泼中$N。$COM", me);						
			return 0;

		case 2:	//触发事件3，冰块：低等伤害，中等忙乱
			message_vision ("$RED$N感觉如坠冰窖,不断有大冰块从空中飞来，四周被击中者哀号连天，又有数块巨冰向$N飞来。", me);						
			return 0;

		case 3:	//触发事件4，热油：强烈伤害，低等忙乱
			message_vision ("四周沸腾起来，杀声震天，$N犹如置身一场攻城大战，城上热油飞溅，眼看自己无幸。", me);						
			return 0;

		case 4:	//触发事件5，阴风：降低防御力
			message_vision ("$N只觉处于鬼域，四外阴风阵阵，身上衣衫单薄，但看要被冻僵。", me);						
			return 0;

		case 5:	//触发事件6，闪电：大变化范围的伤害，中等忙乱。
			message_vision ("忽然天色一亮，无数闪电破云而出，$N吓得抱住身边枯木，又见一道闪电向枯木劈来。", me);						
			return 0;

		case 6:	//触发事件7，灰土：低等伤害，高等忙乱
			message_vision ("$N觉得自己正处于一个垃圾场中，灰土到处飞散，几乎看不见任何东西了。", me);						
			return 0;

  		case 7:	//触发事件8，石块：中等伤害
			message_vision ("$N发现自己正处于一个峡谷，上面不断落下巨大的岩石，一不小心就会被砸中。", me);						
			return 0;

  		case 8:	//触发事件9，地裂：中等伤害，低等忙乱
			message_vision ("整个大地都在强烈的震动中，$N站立不稳，眼看落入裂缝之中。", me);						
			return 0;

		case 9://触发事件10，转移到其他房间
			message_vision ("$N觉得天旋地转，自己正处在一个莫名其妙的扭曲空间之中。", me);
			return 0;
		}

	case 1://未触发1
		message_vision ("只听到极远的地方慕容紫莹纵声狂笑，$N你有几年道行，敢来地狱撒野！", me);
		return 0;
		
	case 2://未触发2
		message_vision ("慕容紫莹阴险的低笑，既然来了，就不要活着出去了。", me);
		return 0;
		
	case 3://未触发3
		message_vision ("慕容紫莹嘿嘿的笑着，你不是很牛X么？看你在这里还装不装英雄。", me);
		return 0;
		
	case 3://未触发4
		message_vision ("慕容紫莹低声告诉你：“其他人身上定有很多宝贝，把他们杀了东西就是你的了。”", me);
		return 0;
	}
	return 0;
*/	
	CRoom::ChangeRoom(me);
}

ROOM_END;