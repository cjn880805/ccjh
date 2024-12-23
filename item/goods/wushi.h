ITEM_BEGIN(CIwushi);

virtual void create(int nFlag = 0)		
{
	set_name( "石人武士", "shi wus hi");
	set("no_get", 1);
	set_weight(10000);
	set("idle",1);
};

virtual int do_look(CChar * me)
{
	say("一尊高大的石人武士。", me);

	if (me->query("teapot/yangguo"))
	{
		AddMenuItem("往前推动", "$9trans $1 a", me);
		AddMenuItem("往后拉动", "$9transx $1 b", me);
		AddMenuItem("转身离开", "", me);
	}
	SendMenu(me);

	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "trans") == 0)
		return do_gox(me, arg);
	if(strcmp(comm, "transx") == 0)
		return do_go(me, arg);
	return 0;
}

int do_go(CChar * me , char  * dest)
{
	if (!strlen(dest))
		return 0;
	long i;
	i=query("idle");
		message_vision("$N用力的把石人往后拉……",me);
		i=i+1;
	set("idle",i);

	if (i==2451)
	{
		set("idle",1);
		message_vision("石人发出嘎吱嘎吱的声音，地面突然露出一个大洞，$N淬不及防，掉了下去！",me);
		me->move(load_room("灵州陵中"));
	}
	return 1;
	
}


int do_gox(CChar * me , char  * dest)
{
	if (!strlen(dest))
		return 0;
	long i;
	i=query("idle");
		message_vision("$N用力的把石人往前推……",me);
		i=i*2;

	set("idle",i);

	if (i==2451)
	{
		set("idle",1);
		message_vision("石人发出嘎吱嘎吱的声音，地面突然露出一个大洞，$N淬不及防，掉了下去！",me);
		me->move(load_room("灵州陵中"));
	}
	return 1;
	
}
ITEM_END;
//1110101000010110101
//23489 19           305  711 712  1425 2851
//    18 38 76 152 304 710       1424 2850
