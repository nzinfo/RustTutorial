# MESI

CPU 的 MESI 缓存一致性协议


## 本地（当前CPU）读写

```sequence
title:PrRd @Invalid

participant C0 as A
participant C1 as O
participant Bus as B
participant M

A-->B: BusRd
Note over O: Copy not I
A-->A: I=>S
Note over O: No Copy
M->B:load
A-->A: I=>E
```

```sequence
title:PrWr @Invalid

participant C0 as A
participant C1 as O
participant Bus as B
participant M

A-->B: BusRdX
Note over O: Copy not I
O-->A: Cache
O-->O: ?=>I
Note right of O: Rd
M-->A: Main Memeory
A->A: I=>M
```

```sequence
title:PrWr @Exclusive

participant C0 as A
participant C1 as O
participant Bus as B
participant M

A->A: E=>M
```

```sequence
title:PrWr @Shared

participant C0 as A
participant C1 as O
participant Bus as B
participant M

A-->B: BusUpgr
A->A: S=>M
O-->O: ?=>I
```

## 远端（其他CPU) 读写

```sequence
title:BusRdX @Invalid

participant C0 as A
participant C1 as O
participant Bus as B
participant M

A->A: I=>I
O-->B: FlushOpt
Note right of O: Flush
O-->A: Cache
M-->A: Main Memeory
```

```sequence
title:BusRd @Exclusive

participant C0 as A
participant C1 as O
participant Bus as B
participant M

A->A: E=>S
A-->B: FlushOpt
Note right of O: Flush
B-->O: to BusRd
```

```sequence
title:BusRd @Modified

participant C0 as A
participant C1 as O
participant Bus as B
participant M

A->A: M=>S
A-->B: FlushOpt
Note right of O: Flush
B-->O: to BusRd
B-->M: Main Memeory
```

```sequence
title:BusRdX @Modified

participant C0 as A
participant C1 as O
participant Bus as B
participant M

A->A: M=>I
A-->B: FlushOpt
Note right of O: Flush
B-->M: Main Memeory
Note over O: Do PrWr
```