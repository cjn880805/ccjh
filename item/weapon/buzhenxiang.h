//buzhenxiang.h

//Sample for ITEM: 布阵箱
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIbuzhenxiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "布阵箱");	//set item name
	
	set_weight(4000);		//set item weight
	
	set("unit", "个");
	set("value", 0l);
	set("jian",5) ;
	set("material", "steel");
	set("long", "这是桃花岛布阵专用的道具：「布阵箱」。里面有各种各样的道具，可以用来布阵。") ;
	
};
/*******************
int do_array(string arg)
{
    object me, obj;
    int myexp , objexp ;
    int mylev , objlev ;
    int steps ;
    me = this_player();
    if( !arg )
        return notify_fail("你想对谁布阵？\n");

    if( environment(me)->query("no_fight") )
       return notify_fail("在这里不能攻击他人。\n");

    if( this_object()->query("jian") <=0)
        return notify_fail("道具已经用光了。\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj == me)
        return notify_fail("你想自杀？ :P\n");
    myexp =  me -> query ("combat_exp" ) ;
    objexp = obj -> query ("combat_exp" ) ;
    mylev =  me -> query_skill("qimen-wuxing" ) ;
    objlev = obj -> query_skill("qimen-wuxing" ) ;

    if ( mylev <= 0 )
        return notify_fail("你不会奇门五行之术，不能布阵！\n");

    myexp = 30 * objexp / myexp ;
    if ( myexp < 30 ) myexp = 30 ;

    if ( me ->query("hp") < myexp )
        return notify_fail("你的精不够了！\n");

    this_object()->add("jian", -1);
    steps = ( mylev - objlev ) / 10  ;
    if ( steps < 2 ) steps = 2 ;
    if ( steps > 8 ) steps = 8 ;
    message_vision(HIY "\n$N拿起布阵箱，在$n周围迅速摆下什么东西......，\n" 
                   "等$n醒过神来却发现自己身陷阵中，动弹不得！\n\n" NOR,
                   me, obj);
    me -> start_busy (3) ;
    if( userp(obj) ) 
	{  	obj -> fight_ob(me) ;
		me->fight_ob(obj);
	}		
    else 
	{	obj->kill_ob(me);
		me->fight_ob(obj);
	}	
    if (  random ( mylev ) < objlev / 2 )
      message_vision("\n但$n很快就识破了$N的阵法，立刻破阵而出！\n" , me, obj);
    else
      {
         tell_object (obj , HIR "\n阵中不断幻出各种各样的怪兽，一个个张牙舞爪\n"
               "向你扑来，你只能集中心力与幻兽相搏！\n" NOR  ) ;
	 obj -> receive_damage ("hp", steps * 10 ) ;	
         obj -> start_busy (steps) ;
	 remove_call_out("out_zhen");
         call_out ("out_zhen" , steps + 2 , obj ) ;
         
      }
    me -> receive_damage ("hp" , myexp ) ;
    return 1;
}
void out_zhen ( object ob )
{
  message_vision("$N长舒了一口气，终于脱出了迷阵！\n"  , ob ); 
}
*************************/
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp