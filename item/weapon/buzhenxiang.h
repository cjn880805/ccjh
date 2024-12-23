//buzhenxiang.h

//Sample for ITEM: ������
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIbuzhenxiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name
	
	set_weight(4000);		//set item weight
	
	set("unit", "��");
	set("value", 0l);
	set("jian",5) ;
	set("material", "steel");
	set("long", "�����һ�������ר�õĵ��ߣ��������䡹�������и��ָ����ĵ��ߣ�������������") ;
	
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
        return notify_fail("�����˭����\n");

    if( environment(me)->query("no_fight") )
       return notify_fail("�����ﲻ�ܹ������ˡ�\n");

    if( this_object()->query("jian") <=0)
        return notify_fail("�����Ѿ��ù��ˡ�\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj == me)
        return notify_fail("������ɱ�� :P\n");
    myexp =  me -> query ("combat_exp" ) ;
    objexp = obj -> query ("combat_exp" ) ;
    mylev =  me -> query_skill("qimen-wuxing" ) ;
    objlev = obj -> query_skill("qimen-wuxing" ) ;

    if ( mylev <= 0 )
        return notify_fail("�㲻����������֮�������ܲ���\n");

    myexp = 30 * objexp / myexp ;
    if ( myexp < 30 ) myexp = 30 ;

    if ( me ->query("hp") < myexp )
        return notify_fail("��ľ������ˣ�\n");

    this_object()->add("jian", -1);
    steps = ( mylev - objlev ) / 10  ;
    if ( steps < 2 ) steps = 2 ;
    if ( steps > 8 ) steps = 8 ;
    message_vision(HIY "\n$N�������䣬��$n��ΧѸ�ٰ���ʲô����......��\n" 
                   "��$n�ѹ�����ȴ�����Լ��������У��������ã�\n\n" NOR,
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
      message_vision("\n��$n�ܿ��ʶ����$N���󷨣��������������\n" , me, obj);
    else
      {
         tell_object (obj , HIR "\n���в��ϻó����ָ����Ĺ��ޣ�һ����������צ\n"
               "������������ֻ�ܼ�������������ಫ��\n" NOR  ) ;
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
  message_vision("$N������һ�����������ѳ�������\n"  , ob ); 
}
*************************/
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp